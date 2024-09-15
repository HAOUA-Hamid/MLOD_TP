Prerequisites
To run the programs in this repository, you will need:

A C compiler such as gcc (GNU Compiler Collection)
Make (for automated build scripts if included)
Optional:
A Linux-based OS or WSL (Windows Subsystem for Linux) for easy compilation and running of the programs.
Folder Structure
Here is a breakdown of the repository:

bash
Copy code
MLOD_TP/
│
├── exo1/                     # Exercises related to basic C concepts
├── exo2/                     # Matrix operations (static and dynamic)
├── exo3/                     # Date manipulation and validation
├── bonus/                    # Additional exercises and advanced topics
├── matrix_library/           # A library for matrix operations in C
└── README.md                 # This README file
Installation
Clone the repository:
bash
Copy code
git clone https://github.com/HAOUA-Hamid/MLOD_TP.git
cd MLOD_TP
Compile the C programs: You can compile any of the C files using gcc. For example:
bash
Copy code
gcc exo1/main.c -o exo1/exo1
./exo1/exo1
(Optional) If there is a Makefile, simply run make:
bash
Copy code
make
This will compile all the necessary files.

Usage
Each exercise has its own folder and can be compiled and run individually. For example, to run a matrix multiplication program from exo2, you would:

bash
Copy code
cd exo2
gcc main.c -o matrix_multiplication
./matrix_multiplication
Follow similar steps for the other exercises.

Example:
exo1 contains basic exercises such as swapping variables.
exo2 deals with matrix operations (both static and dynamic).
exo3 involves date manipulation, including validating a date and determining the day of the year.
Contributing
If you would like to contribute:

Fork the repository
Create a feature branch (git checkout -b feature/AmazingFeature)
Commit your changes (git commit -m 'Add some AmazingFeature')
Push to the branch (git push origin feature/AmazingFeature)
Open a Pull Request
License
This project is licensed under the MIT License - see the LICENSE file for details.
