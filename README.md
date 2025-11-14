# Welcome
An interactive real-time visualization of the QuickSort algorithm built with C++ and SDL2. Watch as data gets recursively partitioned and sorted with smooth animations and color-coded elements to understand one of the most efficient sorting algorithms.

## About 

This project is part of a series of algorithm visualization tools designed to help students and developers understand sorting algorithms through visual representation. QuickSort, known for its exceptional average-case performance, uses a divide-and-conquer strategy that becomes crystal clear when visualized in real-time.

## Features

- 🚀Real-time QuickSort visualization with smooth animation</li>
- 🌈Color-coded elements to distinguish pivot, partitions, and sorted sections</li>
- 🎬Adjustable animation speed for detailed analysis or quick overview</li>
- 📊Multiple data set sizes to observe algorithm behavior at different scales</li>
- 🔎Step-by-step breakdown showing pivot selection and partitioning process</li>
- 🔗Performance metrics display including comparisons and swaps counter</li>
- ⚡Interactive controls for pause, reset, and speed adjustment</li>

## Algotithm Breakdown

The visualization demonstrates the key phases of QuickSort:
1. 🎯 Pivot Selection - Choose an element as the pivot (highlighted in red)
2. 🔄 Partitioning - Rearrange elements so smaller values are on the left, larger on the right (highlighted in orange)
3. 📌 Pivot Placement - Position the pivot in its final sorted location (highlighted in green)
4. 🔁 Recursive Division - Repeat the process on left and right subarrays (highlighted in blue)
5. ✅ Sorted Elements - Elements in their final position (highlighted in white)

## Time Complexity
- Best Case **O(n log n)**
- Average Case **O(n log n)**
- Worst Case **O(n²)**

## Learning Outcomes
This visualizer helps you understand:
- How pivot selection affects partitioning efficiency
- The recursive nature of QuickSort's divide-and-conquer approach
- Why QuickSort is typically faster than other O(n log n) algorithms in practice
- The impact of different input patterns on algorithm performance
- The relationship between comparisons, swaps, and overall efficiency

## Prerequisites

- **C++ compiler** (C++11 or later)
- **SDL2 development libraries**
- **CMake** (optional, for building)

## Contributing

Contributions are welcome! Feel free to:
- Report bugs or suggest features via issues
- Submit pull requests to improve the visualization
- Add new pivot selection strategies (median-of-three, random, etc.)
- Enhance the UI or add new features

## Watch the inspiration video!

<a href="https://www.youtube.com/watch?v=kPRA0W1kECg" target="_blank">
  <img src="https://img.youtube.com/vi/kPRA0W1kECg/maxresdefault.jpg" width="500" alt="YouTube Tutorial - Algorithm Visualizer"/>
</a>


&copy; 2025 GitHub &bull; [Code of Conduct](https://www.contributor-covenant.org/version/2/1/code_of_conduct/code_of_conduct.md)

