#ifndef TESTS_H_INCLUDED
#define TESTS_H_INCLUDED

#include <vector>

#include "Player.h"
#include "Move.h"
#include "Play.h"

Player negation(std::vector<Player>);
void negation_print(std::vector<Player>, Player);
Player conjunction(std::vector<Player>);
void conjunction_print(std::vector<Player>, Player);
Player disjunction(std::vector<Player>);
void disjunction_print(std::vector<Player>, Player);
Player implication(std::vector<Player>);
void implication_print(std::vector<Player>, Player);

class Simple_test
{
  private:

    std::vector<Player> input;

    Player expected_output;

    Player (*get_result)(std::vector<Player> input);

    void (*print_test)(std::vector<Player> input, Player output);

  public:

    Simple_test(std::vector<Player> input_,
                Player expected_output_,
                Player (*get_result_)(std::vector<Player> input),
                void (*print_test_)(std::vector<Player> input, Player output)) :
      input(input_),
      expected_output(expected_output_),
      get_result(get_result_),
      print_test(print_test_)
    {}

    void perform_test()
    {
      std::cout << "Expected: ";
      print_test(input, expected_output);
      std::cout << std::endl;

      Player actual_output = (*get_result)(input);

      std::cout << "Received: ";
      (*print_test)(input, actual_output);
      std::cout << std::endl;

      if (expected_output == actual_output)
      {
        std::cout << "TEST PASSED";
      }
      else
      {
        std::cout << "TEST FAILED";
      }

      std::cout << std::endl;
    }
};

#endif
