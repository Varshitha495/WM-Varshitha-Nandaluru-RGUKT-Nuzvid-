# Software Architecture

## Overview
The software architecture follows a layered, event-driven design that separates sensing,
decision-making, optimization, and visualization responsibilities.

---

## Edge Software Layer

### Data Acquisition Module
- Periodically samples ultrasonic sensor data
- Filters noise and invalid readings

### Fill-Level Computation
- Converts raw distance measurements into fill percentage
- Uses known bin height for normalization

### Threshold Evaluation Algorithm
- Compares fill percentage against predefined threshold
- Marks bin as critical when threshold is exceeded

**Reason for Edge Processing:**
- Reduces unnecessary data transmission
- Enables real-time event detection
- Conserves network bandwidth

---

## Communication Layer

### Protocol: MQTT
- Event-driven publish-subscribe model
- Lightweight and suitable for IoT devices
- Supports scalable many-to-one communication

---

## Cloud Software Layer

### Data Ingestion Service
- Receives bin events from multiple nodes
- Time-stamps incoming data

### Bin Status Classification
- Applies rule-based logic to classify bins
- Generates a list of critical bins

### Route Optimization Module
- Consumes critical bin list and location data
- Generates optimized collection routes
- Operates independently of IoT sensing logic

---

## Application Layer

### Web Dashboard
- Displays real-time bin status
- Shows prioritized bins
- Visualizes optimized routes

---

## Software Design Principles
- Loose coupling between layers
- Event-driven communication
- Replaceable optimization logic
- Horizontally scalable cloud services
