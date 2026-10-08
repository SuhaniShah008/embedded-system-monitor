import pandas as pd
import streamlit as st

st.set_page_config(
    page_title="Embedded System Monitor",
    page_icon="📟",
    layout="wide"
)

st.title("Embedded System Performance Monitor")
st.caption("Telemetry dashboard for simulated embedded-system metrics")

DATA_FILE = "data/system_metrics.csv"

try:
    df = pd.read_csv(DATA_FILE)
except FileNotFoundError:
    st.error(
        "Telemetry data was not found. Run the C++ monitor first to create "
        "data/system_metrics.csv."
    )
    st.stop()

latest = df.iloc[-1]

col1, col2, col3, col4 = st.columns(4)

col1.metric("Temperature", f"{latest['temperature_c']:.1f} °C")
col2.metric("CPU Usage", f"{latest['cpu_percent']:.1f}%")
col3.metric("Memory Usage", f"{latest['memory_percent']:.1f}%")
col4.metric("Voltage", f"{latest['voltage_v']:.2f} V")

st.subheader("System Telemetry")

chart_data = df.set_index("sample")[
    ["temperature_c", "cpu_percent", "memory_percent"]
]
st.line_chart(chart_data)

st.subheader("Voltage")
st.line_chart(df.set_index("sample")[["voltage_v"]])

alerts = df[df["status"] == "ALERT"]

st.subheader("Detected Alerts")
if alerts.empty:
    st.success("No abnormal readings detected.")
else:
    st.warning(f"{len(alerts)} abnormal readings detected.")
    st.dataframe(alerts, use_container_width=True)

st.subheader("Raw Telemetry")
st.dataframe(df, use_container_width=True)
