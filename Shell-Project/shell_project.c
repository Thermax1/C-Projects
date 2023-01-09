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
  ssize_t bufsize = 0; //will have getline allocate a buffer for us. ssize_t is he same as size_t, but is a signed type. This is TYPE of the result returned by sizeof operator 

  if(getline(&line,&bufsize,stdin) == -1){
    if (feof(stdin)){ //feof(function) indicates whether the EOF flag is set for the given stream
      exit(EXIT_SUCCESS); //We got an EOF
    } else {
      perror("readline"); //perror prints an error message to stderr
      exit(EXIT_FAILURE)
    }
  }

  return line;
}
*****************************************************************/

/*****************************************************************
Parsing the Line
1.We will be simplifying, not allowing quotes or backslash escapes into command line arguments
2. Will use whitespace to separate arguments
3. We will use whitespace as delimiters
*****************************************************************/

#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM "\t\r\n\a"
char **lsh_split_line(char *line) {

  int bufsize = LSH_TOK_BUFSIZE, position = 0;
  char **tokens = malloc(bufsize *sizeof(char*));
  char *token;

  if (!tokens) {
    fprintf(stderr, "lsh: allocation error\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(line, LSH_TOK_DELIM); //breaks string into series of tokens using delimiter. Returns a pointer to first character of a token or null pointer if there is no token.
  while(token != NULL) {
    tokens[position] = token; //each pointer is stored in an array (buffer) of character pointers
    position++;

    if (position >= bufsize) {
      bufsize += LSH_RL_BUFSIZE;
      tokens = realloc(tokens, bufsize *sizeof(char*));
      if(!tokens) {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }

    token = strtok(NULL, LSH_TOK_DELIM);
  }
  tokens[position] = NULL;
  return tokens;
}

/*****************************************************************
 How Shells Start Processes
 1. Unix computer boots, kernel loads. Kernel starts ONE process called "Init". Apparently, this almost doesn't count
 2. fork() system call. OS makes duplicate of process and starts them both running. Parent is original, child is new one.
3. fork() returns 0 to child process, and it returns to the parent the PID of its child.
  - Essentially means that the only way for new processes to start is by existing one duplicating itself
  - Sounds like a problem. What if you want to run a new process? You don't want a copy of the same program. There is a solution.
4. exec() system call replaces current running program with an entirely new one. OS stops procss, loads up new program, and starts that one in its place.
  - Processes never return from exec() call unless an error happens
5. So we have to have an existing proves fork itself into two seperate ones. THEN the child uses exec() to replace itself with a new program.
6. Parents can do other things and even keep tabs on children using wait() system call.
7. Finally, my OS class is starting to make sense
*****************************************************************/

int lsh_launch(char **args) {
  pid_t pid, wpid; //data type that represents process IDs
  int status;

  pid = fork();
  if(pid == 0) {
    // this is the child process
  }
}