/*****************************************************************
Shell Main Functions
1. Initialize. Read/execute config files. Will change aspects of shell behavior
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
  
  int bufsize = LSH_RL_BUFSIZE;
  int position = 0;
  char *buffer = malloc(sizeof(char) *bufsize);
  int c;

if(!buffer) { //! reverses meaning of operand. Only works for arithmetic or pointer type
  fprintf(stderr, "lsh: allocation error\n"); //Prints content in file instead of stdout
  exit(EXIT_FAILURE);
}

while(1){
  //Read a character
  c = getchar(); //Stored as int because EOF is an integer and that's how we check for it

  //If we hit EOF, replace with null character and return

  if(c == EOF || c == '\n') {
    buffer[position] = '\0'; //This is a null character or terminator
    return buffer;
  } else {
    buffer[position] = c;
  }
  position++;

  //If we exceed the buffer, we reallocate
  if(position >= bufsize) {
    bufsize += LSH_RL_BUFSIZE;
    buffer = realloc(buffer, bufsize);

    if(!buffer){
      fprintf(stderr, "lash: allocation error\n");
      exit(EXIT_FAILURE);
    }
  }
}
}

/*****************************************************************
1. For my reference, C has a getline() function in stdio.h that does most of the code above easily. I will demonstrate it now

char *lsh_read_line(void)
{
  char *line = NULL;
  ssize_t bufsize = 0; //will have getline allocate a buffer for us

  if(getline(&line,&bufsize,stdin) == -1){
    if (feof(stdin)){
      exit(EXIT_SUCCESS); //We got an EOF
    } else {
      perror("readline");
      exit(EXIT_FAILURE)
    }
  }

  return line;
}
*****************************************************************/