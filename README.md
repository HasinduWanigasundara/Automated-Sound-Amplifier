# 🔊 AUTOMATED SOUND REGULATOR

---

<p align="center">
  <img src="images/Final_Device.png" alt="Skynet Tronics Automated Sound Regulator" width="800">
</p>

## Project Header

**Skynet Tronics** presents a project for the **EN-1190 ENGINEERING DESIGN PROJECT** module.

**Institution:** University of Moratuwa

**Team Members:**
*   H.A.P. Aroshana (230058N)
*   H.D.J.D. Samaranayaka (230563Η)
*   W.M.H. Wanigasundara (230680M)
*   A.H.T.M. Weerakoon (230689A)

---

## 📖 Table of Contents

- [Project Overview](#project-overview)
- [System Architecture](#system-architecture)
- [Design and Specifications](#design-and-specifications)
- [Technical Details](#technical-details)
- [Prototype Development](#prototype-development)
- [Testing and Stakeholder Feedback](#testing-and-stakeholder-feedback)
- [Limitations and Future Work](#limitations-and-future-work)

---

## Project Overview

### Problem Statement

Effective communication is critical when addressing an audience. However, the acoustics of different spaces and variations in speaking styles and voice levels pose practical challenges. For instance, in a setting with multiple speakers, each might require a specific audio system setting, but a single technician can only provide fixed adjustments. This can lead to uneven audibility, reducing audience engagement and potentially causing hearing damage due to overamplification. Our research among stakeholders confirms that fluctuating sound levels are a common and widespread problem.

### Our Solution

To address this issue, we propose the development of an external volume adjustment device, which we have named the **Automated Sound Regulator (ASR)**. This standalone system is designed to be user-friendly, modular, and easy to integrate with existing audio setups without requiring modifications to the main amplifier.

---

## System Architecture

The ASR is designed to be an automated device with key components focusing on different aspects of signal processing. The main operational flow is as follows:

1.  **Signal Monitoring Unit:** Continuously samples the output signal from the main amplifier or a central sound source.
2.  **Threshold Analysis Module:** Determines if the current audio level is within an acceptable, calibrated range.
3.  **Dynamic Gain Adjustment Unit:** Automatically modifies the audio to maintain a stable, optimal output level.
4.  **Configuration and Calibration Setup:** Enables customization of the system's operational thresholds for different environments.

<p align="center">
  <img src="images/system_flowchart.png" alt="Operational Flowchart of the Automated Sound Regulator" width="600">
  <br>
  <em>Overall operational flowchart of the ASR system.</em>
</p>

### Unique Value

Unlike typical audio solutions with fixed thresholds, our ASR offers a unique level of control with customizable, scene-specific calibration. As an external, standalone device, it provides dynamic adjustment without any need to replace or alter existing amplifiers. This makes it an affordable and highly adaptive solution for a variety of spaces, from small meeting rooms to large auditoriums.

---

## Design and Specifications

We focused heavily on the user interface and user experience, creating a design that is both functional and ergonomic. The device features a set of control knobs for min/max levels, clear input/output jacks, and built-in ventilation to ensure reliable performance. Its modular and compact design ensures it is easy to transport and deploy.

| Specification | Dimension |
| :--- | :--- |
| **Length** | 20 cm |
| **Height** | 6 cm |
| **Depth** | 15 cm |

<p align="center">
  <img src="images/ui_views.png" alt="Front, Side, and Back Views of the ASR with Dimensions" width="800">
  <br>
  <em>Dimensional views of the device's exterior.</em>
</p>

---

## Technical Details

The development of the ASR posed several interesting technical challenges, especially around the dynamic range and real-time response of the analog audio signal.

### Challenges Faced

*   **Digital Potentiometer Limitations:** Working with digital potentiometers to achieve precise, step-less control of the signal proved to be complex.
*   **Microphone-based Signal Monitoring:** Ensuring accurate sound monitoring from ambient noise, rather than just the direct signal, was a key design challenge that we tackled through iterative testing.

### Schematic Design

You can view the full schematic diagrams for the project, showcasing the power, signal processing, and microcontroller interfacing stages of the circuit.

<p align="center">
  <img src="images/full_schematic.png" alt="Full Schematic Diagram of the ASR circuit" width="800">
  <br>
  <em>Complete project schematic diagram.</em>
</p>

---

## Prototype Development

Our project followed a rigorous engineering development life cycle. We started with breadboard-based proof-of-concepts, iteratively improving the circuit layout.

| Stage | Photo |
| :--- | :--- |
| **Initial Prototype on Breadboard** | <img src="images/initial_prototype.png" alt="Initial breadboard prototype" width="300"> |
| **Advanced Perfboard Prototype** | <img src="images/advanced_prototype.png" alt="Intermediate perfboard prototype with power supply" width="300"> |
| **Final Product** | <img src="images/final_product_isolated.png" alt="Finished 3D-printed final product" width="300"> |

---

## Testing and Stakeholder Feedback

We conducted an extensive testing phase and a comprehensive stakeholder review to validate the problem and our solution. Our surveyed stakeholders included speakers, audience members, institutional managers, and professional audio engineers.

### Testing and Validation Flowchart

Our final testing followed a structured path:
1.  Stakeholder Survey
2.  Initial Prototype Development & Testing
3.  PCB and Enclosure Design
4.  Challenges and Fixes
5.  Testing the Final Product

<p align="center">
  <img src="images/testing_flowchart.png" alt="Structured testing flowchart" width="600">
  <br>
  <em>Flowchart detailing the testing and iterative fix phases.</em>
</p>
<br>
### Feedback Summary

The stakeholder review confirmed the clear necessity for such a solution. We received exceptionally positive feedback, with a high rating indicating strong support for our automated, external dynamic adjustment solution. Stakeholders noted that fluctuating audio levels are indeed a major pain point, emphasizing that a solution that works with existing amplifiers without extensive modification would be highly valuable.

---

## Limitations and Future Work

While our solution is unique and robust, we are aware of several limitations:
*   Dependency on an initial test run for environment-specific calibration.
*   The assumption of relatively stable environmental conditions (which may not always be true in every setting).
*   Potential for dependencies on the inherent quality, dynamic range, and responsiveness of the existing audio system.

We look forward to future work that will address these limitations, potentially through more advanced AI-driven calibration routines and improved signal monitoring algorithms.
