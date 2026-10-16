
cmake_minimum_required(VERSION 3.16)

project(SmartInventoryIntelligenceSystem
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(smart_inventory
    main.cpp

    src/product/Product.cpp
    src/product/Inventory.cpp

    src/sales/Sale.cpp
    src/sales/SalesHistory.cpp

    src/restocking/Alert.cpp
    src/restocking/PurchaseOrder.cpp
    src/restocking/Restocking.cpp

    src/supplier/Supplier.cpp
    src/supplier/Warehouse.cpp
    src/supplier/DeliveryGraph.cpp

    src/common/FileManager.cpp
)

target_include_directories(smart_inventory PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(smart_inventory PRIVATE
        -Wall
        -Wextra
        -Wpedantic
    )
endif()
