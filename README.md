# Land Categorization System in C++

This project is a **Land Categorization System** built using C++ and the **Qt framework**. It provides an interactive graphical interface where users can classify different types of land (Agricultural or Commercial) based on selected features. The program assigns marks to each selected feature and calculates a grade for the land.

## Features

- **Two Land Categories**: 
  - **Agricultural Area**: Allows selection of features like irrigation facility, road access, crop type, soil quality, altitude, market proximity, and elevation.
  - **Commercial and Residential Area**: Provides options for road type, water, electricity, location type, transport, communication, sewerage, and residency type.
- **Marks Calculation**: The app calculates a total score based on the selected options and assigns a grade to the land category.
- **Interactive Interface**: Built using Qt's `QComboBox`, `QLabel`, `QTextEdit`, and `QPushButton` for a user-friendly experience.
- **Multi-panel Navigation**: Uses `QStackedWidget` to switch between the main selection, agricultural, and commercial panels.

## Grading System

The program assigns grades based on a scoring system for each land category:

- **Agricultural Grades**:
  - **1a Grade**: 46 or more points
  - **1b Grade**: 36-45 points
  - **1c Grade**: 26-35 points
  - **1d Grade**: 16-25 points
  - **1e Grade**: 1-15 points
  - **Ungraded**: 0 points

- **Commercial Grades**:
  - **2a Grade**: 41 or more points
  - **2b Grade**: 31-40 points
  - **2c Grade**: 21-30 points
  - **2d Grade**: 11-20 points
  - **2e Grade**: 1-10 points
  - **Ungraded**: 0 points



## Getting Started

### Prerequisites

- Install **Qt**. You can download it from [here](https://www.qt.io/download).
- A C++ compiler (like GCC or MSVC) compatible with Qt.

### Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/prabhatbhusal/land-categorization-system.git
   cd land-categorization-system
