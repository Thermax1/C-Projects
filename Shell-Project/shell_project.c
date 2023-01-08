/*****************************************************************
Shell Main Functions
1. Initialze. Read/executre config files. Will change aspects of shell behavior
2. Interpret. Shell reads commands from stdin (interactive or file) and executes the,
3. Terminate. After commands are executed, shell does shutdown commands, free up memory, and terminates

*****************************************************************/

int main(int argc, char **argv) {

  //Load config files if any
  
  //Run command loop.
  lsh_loop();
  
  //perform any shutdown/cleanup.
  
  return EXIT_SUCCESS;
}

/*****************************************************************
Basic Loop Logic for Shell
1. Read. Reads command from standard input
2. Parse. Seperate command string into program and arguments
3. Execute. Run the parsed command
******************************************************************/

void lsh_loop(void) {//No return and nothing inside the parameters
  
  char *line;
  char **args;
  int status;
  
  do{
    printf("> ");
    line = lsh_read_line(); //Function to read line. 
    args = lsh_split_line(line); //Splits line into arguments
    status = lsh_execute(args); //Execute the arguments split up from previous function
    
    free(line);
    free(args);
  }while (status); //Do-While is best because it executes once before checking the value to see if we continue.
}

/*****************************************************************
How to Read a line in C. Self-Learning == Success
1. Can be a hassle in C
2. Will never know how much text user enters
3. Start with a block. If exceeded, reallocate with more space
4. This is a common strategy in C, apparently.
*****************************************************************/
#define LSH_RL_BUFSIZE 1024 //Defines macros in a C program. Declares constant values or expression.
char *lsh_read_line(void) {
   
   int bufsize = LSH_RL_BUFSIZE
}
