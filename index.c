//COMPILER BASED INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//CREATE STRUCTURES FOR LINKED LISTS AND PROCESS SIMULATION
#include "includes/structures.c"
//IMPLEMENTS FUNCTION CALLS AND STATES FOR APPLICATION
#include "includes/global.c"

//MAIN FUNCTION
int main(int argc, char const *argv[]) {

  //VARIABLES FROM CONFIG FILE WILL BE SAVED TO VARIABLE ARR[]
  //THERE ARE 12 VARIABLES FROM CRONFIG SO HENCE 12 ARR VALUES
  #include "includes/config.c"

  //RUN SIMULATION
  #include "includes/simulation.c"

  return 0;
}
//ACTUAL FUNCTION CODE
#include "includes/functions.c"
