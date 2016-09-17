# OsSim
Operating System Simulator for CS 410 Operating Systems 

# Technical Support Manual 
--- 

## Table of Contents 

| Title | Description | 
| ------ | ---- | 
| [Overview of the Program](#overview-of-program) | Program Flow/What the system does | 
| [Program Structure](#program-structure) | UML Diagrams and List of contents in each file | 
| [Functions](#functions) | Prototype/Parameters/Return Values | 
| [Data Structures and Classes](#data-structures-and-classes) | Use/Attributes | 
| [Global Variables](#global-variables) | Data Types/Use | 
| [Cross References](#cross-references) | Which functions call which functions | 
| [Index](#index) | Common key words you may need to locate quickly |

[Link to a header](#awesome-section)

## Overview of Program

This program acts as a command shell. It's purpose is to simulate an operating system. The "meat" of the program can be found in commandHandler.cpp. This class is responsible for parsing user commands and executing the correct set of instructions. The command handler utilizes a commandDictionary that will provide the object with the command code so that it can easily match a string to a unique code. This code is then used to start the execution of the command input by the user.     

##Program Structure 

![Alt text](UMLDiagram.png?raw=true "Optional Title")

##Functions 

## Data Structures and Classes 

## Global Variables 

## Cross References 

## Index 
