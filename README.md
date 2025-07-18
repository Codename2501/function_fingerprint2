# Geometric Fingerprint Framework

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

An original conceptual framework for visualizing the local properties of a function or system as a unique "geometric fingerprint" on the complex plane.

![Sinc Function Trajectory](https://i.imgur.com/iJ8q3hZ.png)
*(The trajectory of H for the function f(x) = sin(x)/x)*

---

## 📖 Overview

This project provides a unique method for analyzing mathematical functions and systems described by differential equations. The framework takes a function `f(x)` and its first three derivatives (`f'`, `f''`, `f'''`) at a given point `x` and integrates this information into a single characteristic complex vector, `H`.

By plotting the trajectory of this vector `H` on the complex plane as `x` varies, we can generate a "geometric fingerprint." This fingerprint is a visual signature that reveals the intrinsic mathematical characteristics of the function or system, such as its periodicity, stability, singularities, or chaotic behavior.

### The Core Concept: Integration via Geometric Mean

The essence of this framework is its method of combining different aspects of the function's local behavior. It translates the function and its derivatives into unit vectors (`h_k`) on the complex plane. It then calculates their **additive interaction (`H₁`)** and **multiplicative interaction (`H₂`)**. These two components are elegantly unified via a **geometric mean** to produce the final fingerprint vector, `H`.

$$
h_k = \frac{1 + f^{(k)}(x) \cdot i}{\sqrt{1 + (f^{(k)}(x))^2}}
$$

$$
H_1 = \frac{h_0 + h_1 + h_2 + h_3}{4}
$$

$$
H_2 = h_0 \cdot h_1 \cdot h_2 \cdot h_3
$$

$$
H = \sqrt{H_1 \cdot H_2} \cdot 2^{-n}
$$

---

## ✨ Gallery of Fingerprints

This framework produces unique and often beautiful fingerprints for different functions.

| Function / System | Generated Geometric Fingerprint |
| :--- | :---: |
| **`f(x) = sin(x)`** | ![sin(x) Trajectory](https://i.imgur.com/gK9R4o8.png) |
| **`f(x) = x^4`** | ![x^4 Trajectory](https://i.imgur.com/XF8J5aD.png) |
| **Spring Oscillator (RK4)** | ![Spring Trajectory](https://i.imgur.com/G4gA3rJ.png) |

*(Note: These are example images. You should replace them with your own generated graphs.)*

---

## 🚀 How to Use

The process involves two steps: generating the data with the C program and then visualizing it with a tool like Gnuplot.

### 1. Generate Data

Modify the C source file to define the function and derivatives you wish to analyze. Then, compile and run the program, piping the output to a data file.

```sh
chmod +x framework.sh
./framework.sh
command+Q
