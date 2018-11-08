// My first C++ program!    <-- This is a comment
                            // Comments allow us to better document our code
                            // so that we can understand it easier.
                            // This class will require more comments than are
                            // usually acceptable, but that is because I need
                            // you to demonstrate your knowledge.

                            /* At any point in a line, the double forward slash
                             * indicates that everything after AND on the same
                             * line is a comment. You can also start a block
                             * comment with a slash-star. Everything after the
                             * slash-star is considered a comment until you 
                             * reach the end block comment, star-slash.
                             */

#include <iostream>         // A preprocessor directive. This speaks directly
                            // to the compiler. 

using namespace std;        // C++ contains many namespaces. By specifying that
                            // that we are using the std namespace, we are just
                            // saving some typing. For example, without this
                            // 'using' line, we would have to write std::cout,
                            // because the command cout belongs to the std
                            // namespace

int main()      			// Every C++ program must have a main function
{            
                            // Its type must be int. It can have void parameters
                            // as shown, or it can look like this:
                            // int main (int argc, char* argv[])
                            // The opening bracket indicates the beginning of a
                            // block of code

  cout << "Hello World!\n"; // This is the line that prints to the screen
							// The "\n" is a special character which tells
							// the compiler that a new line is wanted after the
							// exclamation mark

  return 0;                 // A return statement terminates a function. The
                            // main function needs to return 0 at some point
                            // because it indicates a successful execution of
                            // the program. Functions can have multiple return
                            // statements

}                           // Signifies the end of a code block. Blocks can be
                            // nested, i.e., blocks can contain blocks. Proper
                            // styling becomes very important to keep track of
                            // complicated code.
