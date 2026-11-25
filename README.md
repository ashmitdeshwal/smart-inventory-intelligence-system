# Smart Inventory Intelligence System

A C++17 console-based inventory management project that uses Object-Oriented Programming (OOP) and Data Structures and Algorithms (DSA) to support inventory tracking and intelligent restocking decisions.

## Overview

The Smart Inventory Intelligence System helps manage product stock and identify items that need replenishment. It analyses available quantity, daily sales, and supplier delivery time to generate restocking alerts and prioritize purchase orders.

The project is developed in C++ and organized into separate modules to support maintainability and further development.

## Features

- **Product Management:** View existing products and add new products.
- **Inventory Tracking:** Maintain product quantities, daily sales, and delivery information.
- **Intelligent Restocking:** Calculate reorder points using daily sales and delivery time.
- **Stock-Out Estimation:** Estimate how many days the current stock may last.
- **Priority-Based Alerts:** Classify restocking urgency as Critical, High, or Medium.
- **Purchase Order Queue:** Prioritize restocking orders using a priority queue.
- **Modular Structure:** Organize functionality into separate source and header files.

## Technologies Used

- **Language:** C++
- **Standard:** C++17
- **Concepts:** Object-Oriented Programming (OOP), Data Structures and Algorithms (DSA)
- **Data Structures:** Arrays and Priority Queue
- **Build System:** CMake
- **Version Control:** Git and GitHub

## Restocking Logic

The restocking module uses the following calculations:

**1. Estimated Days Until Stock-Out**

`Days Left = Current Quantity / Daily Sales`

**2. Reorder Point**

`Reorder Point = Daily Sales × (Delivery Days + Buffer Days)`

**3. Order Quantity**

`Order Quantity = Reorder Point - Current Quantity`

Products that reach or fall below their reorder point are considered for replenishment.

Restocking urgency is classified as:

- **Critical:** Stock may run out within the supplier delivery period.
- **High:** Stock may run out shortly after the delivery period.
- **Medium:** Restocking is required, but the estimated stock-out time is longer.

A priority queue is used to display higher-priority purchase orders first.

## Project Structure

```text
smart-inventory-intelligence-system/
│
├── main.cpp
├── CMakeLists.txt
├── README.md
├── .gitignore
│
├── include/
│   ├── Restocking.h
│   └── Other module headers
│
├── src/
│   ├── product/
│   ├── sales/
│   ├── restocking/
│   ├── supplier/
│   └── common/
│
├── data/
├── docs/
└── tests/
```

## Getting Started

### Prerequisites

Install the following:

- A C++17-compatible compiler (GCC or MinGW)
- CMake 3.16 or later
- Git

### Clone the Repository

```bash
git clone https://github.com/ashmitdeshwal/smart-inventory-intelligence-system.git
```

Move into the project directory:

```bash
cd smart-inventory-intelligence-system
```

### Build on Windows Using MinGW

Configure the project:

```powershell
cmake -S . -B build -G "MinGW Makefiles"
```

Compile:

```powershell
cmake --build build
```

Run:

```powershell
.\build\smart_inventory.exe
```

## Current Console Menu

The current main program provides these options:

1. View Products
2. Add Product
3. Check Restocking Alerts
4. Exit

## Learning Outcomes

Working on this project provides practical experience with:

- C++ programming and modular code organization
- Object-Oriented Programming concepts
- Arrays and priority queues
- Inventory and restocking calculations
- CMake-based project compilation
- Git and GitHub collaboration

## Future Improvements

- Integrate additional inventory and supplier modules into the main application.
- Improve data persistence and reporting.
- Add a graphical user interface.
- Introduce more comprehensive automated tests.
- Expand inventory analytics and forecasting capabilities.

## Repository

GitHub: https://github.com/ashmitdeshwal/smart-inventory-intelligence-system

---

**Note:** This project is being developed and improved as part of a hands-on C++ software development project.