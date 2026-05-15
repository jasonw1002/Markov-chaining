#include "curve.hpp"
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) 
{
    bool fileCommands = false;

    if(argc != 4) {
        cout << "Usage: ./Naive_classification [likelihood.txt] [training.txt] [testing.txt]" << endl;
        exit(EXIT_FAILURE);
    }

    //likelihood 
    ifstream instream;
    instream.open(argv[1]);

    if(!instream.is_open()) {
        cout << "Couldn't open file" << endl;
        exit(EXIT_FAILURE);
    }

    Curve c = Curve();
    Markov *m = new Markov[NUMBER_OF_TESTS];

    c.process_likelihoods(instream);

    instream.close();

    //training data
    instream.open(argv[2]);
    if(!instream.is_open()) {
        cout << "Couldn't open file" << endl;
        exit(EXIT_FAILURE);
    }

    //test data
    c.process_training(instream);

    instream.close();

    instream.open(argv[3]);

    if(!instream.is_open()) {
        cout << "Couldn't open file" << endl;
        exit(EXIT_FAILURE);
    }

    //calculates probabilities
    c.bayes(m, instream);

    instream.close();
 
}
