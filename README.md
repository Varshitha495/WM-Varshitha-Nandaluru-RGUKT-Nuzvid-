# Smart Waste Bin Network  
Virtual IoT Design Challenge

---

## 1. Problem Definition
Conventional waste collection systems operate on fixed schedules without real-time visibility of bin utilization. This results in bin overflow in high-demand areas and inefficient use of collection resources in low-demand areas.  

The objective of this system is to design an IoT-based waste monitoring framework that enables condition-based waste collection using real-time sensing and centralized decision making.

---

## 2. System Architecture Overview
The system is divided into four logical layers:

- Sensing Layer  
- Edge Processing Layer  
- Communication Layer  
- Cloud and Application Layer  

Each layer is designed with specific technology choices justified based on system constraints.

---

## 3. Sensing Layer

### 3.1 Sensor Selection
**Sensor Used:** Ultrasonic Distance Sensor  

### 3.2 Reason for Selection
- Non-contact measurement avoids sensor damage due to waste  
- Reliable operation across varying waste types  
- Low cost and low power consumption  
- Suitable for measuring fill level in enclosed bins  

### 3.3 Function
The ultrasonic sensor measures the distance between the sensor mounted at the top of the bin and the waste surface. This distance is converted into a fill percentage based on the known bin height.

---

## 4. Edge Processing Layer

### 4.1 Controller Used
**Controller:** ESP32 Microcontroller  

### 4.2 Reason for Selection
- Built-in wireless communication capability  
- Sufficient computational power for local preprocessing  
- Low power operation suitable for battery-based systems  
- Widely supported development ecosystem  

### 4.3 Edge Algorithm
**Algorithm Used:** Threshold-Based Fill Level Evaluation  

### 4.4 Algorithm Description
- Sensor readings are sampled periodically  
- Distance values are converted into fill percentage  
- A predefined threshold is applied  
- If the fill level exceeds the threshold, the bin is marked as critical  

### 4.5 Reason for Algorithm Choice
- Simple and deterministic decision making  
- Low computational overhead  
- Suitable for real-time event detection  
- Easy to scale across multiple bins  

---

## 5. Communication Layer

### 5.1 Protocol Used
**Protocol:** MQTT  

### 5.2 Reason for Selection
- Lightweight messaging protocol suitable for IoT devices  
- Low bandwidth consumption  
- Supports publish–subscribe architecture  
- Reliable message delivery with minimal overhead  

### 5.3 Communication Strategy
- Event-driven data transmission  
- Data sent only when threshold conditions are met  
- Reduces network congestion and power usage  

---

## 6. Cloud Processing Layer

### 6.1 Cloud Functions
- Data ingestion from multiple bin nodes  
- Time-stamped data storage  
- Status classification of bins  
- Aggregation of critical bins  

### 6.2 Cloud Algorithm
**Algorithm Used:** Rule-Based Classification  

### 6.3 Algorithm Description
- Incoming bin data is compared against defined fill-level rules  
- Bins are classified as normal or critical  
- Critical bins are flagged for collection  

### 6.4 Reason for Algorithm Choice
- Transparent and explainable decision logic  
- Easy to modify thresholds based on policy  
- Suitable for early-stage smart city deployments  

---

## 7. Application and Decision Layer

### 7.1 Dashboard Functionality
- Real-time visualization of bin status  
- Priority-based bin listing  
- Summary of collection requirements  

### 7.2 Decision Strategy
- Only bins marked as critical are considered for collection  
- Enables condition-based waste collection  
- Eliminates unnecessary collection trips  

---

## 8. Route Optimization Strategy

### 8.1 Role of Route Optimization in the System
The Smart Waste Bin Network identifies bins that require collection based on real-time fill-level data. Once bins are classified as critical, a route optimization strategy is applied to determine an efficient collection sequence for waste collection vehicles.

Route optimization is treated as a downstream decision module that consumes processed bin data from the cloud layer.

---

### 8.2 Input to the Route Optimization Module
The optimization module receives the following inputs from the cloud system:

- List of bins marked as critical  
- Geographical coordinates of each bin  
- Vehicle capacity constraints  
- Depot or starting location of the collection vehicle  

---

### 8.3 Optimization Strategy Used
**Strategy:** Priority-Based Shortest Path Routing  

### 8.4 Algorithm Description
- Bins are filtered based on critical status  
- Critical bins are sorted based on urgency level  
- Bins are grouped geographically to reduce travel distance  
- Within each group, the shortest path between bins is computed  
- Routes are updated dynamically as new bin events are received  

### 8.5 Algorithm Choice Justification
This strategy is selected because:
- It minimizes total travel distance  
- It reduces fuel consumption and collection time  
- It supports incremental updates when new bins become critical  
- It avoids computational complexity of full vehicle routing solvers  
- It is suitable for real-time smart city deployments  

---

## 9. Integration with the IoT System
- Route optimization is executed at the cloud layer  
- Optimized routes are exposed to the dashboard  
- The IoT system remains decoupled from vehicle navigation logic  
- Routing logic can be replaced without modifying sensing or communication layers  

---

## 10. Optional Enhancements (Future Scope)
- Traffic-aware routing  
- Multi-vehicle coordination  
- Machine learning-based demand prediction  

---

## 11. Scalability Considerations
- Independent operation of each bin node  
- Event-driven communication reduces network load  
- Cloud architecture supports horizontal scaling  
- Additional bins can be added without system redesign  

---

## 12. Conclusion
This system demonstrates a technically justified IoT architecture for smart waste management. Each design choice, including sensor selection, communication protocol, and algorithm design, is made to ensure reliability, scalability, and efficient decision making in urban environments.
