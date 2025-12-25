# Hardware Architecture

## Overview
The hardware architecture defines the physical components deployed at each waste bin node.
Each node is designed to operate autonomously, perform local sensing and preprocessing,
and communicate events to the cloud infrastructure.

---

## Bin Node Components

### Ultrasonic Distance Sensor
**Function:** Measures the distance between the bin lid and waste surface.

**Justification:**
- Non-contact sensing avoids damage from waste materials
- Reliable for enclosed environments
- Low cost and low power consumption
- Suitable for fill-level estimation

---

### ESP32 Microcontroller
**Function:** Performs local data processing and communication.

**Justification:**
- Integrated Wi-Fi capability
- Sufficient computational power for preprocessing
- Low power operation for distributed deployments
- Strong ecosystem support

---

### Power Supply
**Configuration:** Battery or mains-powered (deployment dependent)

**Justification:**
- Supports autonomous bin operation
- Enables flexible installation across urban locations

---

## Hardware Interaction Summary
- The ultrasonic sensor periodically measures fill level
- ESP32 converts raw distance into fill percentage
- Threshold evaluation is performed locally
- Only significant events are transmitted to the cloud

---

## Scalability Considerations
- Each bin node operates independently
- Failure of one node does not affect others
- Additional bins can be deployed without redesign
