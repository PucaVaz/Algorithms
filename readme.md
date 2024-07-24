# Sorting Algorithms Benchmark

This simple project benchmarks two sorting algorithms (Selection Sort and Insertion Sort) on multiple input files of numeric data. 

## How to Run

1. **Compile the program**:
    ```sh
    make 
    ```

2. **Execute the program**:
    ```sh
     ./sorting 
    ```

## Description

The program reads numeric data from a series of input files located in the `instancias-numericas` directory and measures the time taken to sort the data using two different algorithms: Selection Sort and Insertion Sort. 

### Input Files

- The input files are located in the `instancias-numericas` directory.
- Each file contains a list of numbers to be sorted.

### Scenarios

- **Scenario 1**: Selection Sort with Array
- **Scenario 2**: Insertion Sort with Array

### Output

For each input file, the program will print the time taken to sort the numbers using each algorithm. At the end, it will summarize the time taken for each scenario.

## Example Output

```plaintext
Selection Sort with Array: instancias-numericas/num.1000.1.in
Time taken for instancias-numericas/num.1000.1.in: 0.002345 seconds

Insertion Sort with Array: instancias-numericas/num.1000.1.in
Time taken for instancias-numericas/num.1000.1.in: 0.001234 seconds

...

Time taken for each scenario: 
Scenario 0: 0.002345
Scenario 1: 0.001234
```

## Dependencies

- Standard C library

## Authors

- Puca Vaz

---