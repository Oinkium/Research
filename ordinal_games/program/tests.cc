#include <iostream>
#include "tests.h"

int main()
{
  // TEST 1: negation.

  std::cout << "TEST 1 - NEGATION" << std::endl;
  std::cout << "-----------------" << std::endl << std::endl;

  Simple_test negation_test_cases[2] = {
    Simple_test( { P }, O, negation, negation_print),
    Simple_test( { O }, P, negation, negation_print)
  };

  for (int i = 0 ; i < 2 ; ++i)
  {
    negation_test_cases[i].perform_test();
  }

  std::cout << std::endl;

  // TEST 1: conjunction.

  std::cout << "TEST 1 - CONJUNCTION" << std::endl;
  std::cout << "-----------------" << std::endl << std::endl;

  Simple_test conjunction_test_cases[4] = {
    Simple_test( { P, P }, P, conjunction, conjunction_print),
    Simple_test( { P, O }, O, conjunction, conjunction_print),
    Simple_test( { O, P }, O, conjunction, conjunction_print),
    Simple_test( { O, O }, O, conjunction, conjunction_print),
  };

  for (int i = 0 ; i < 4 ; ++i) {
    conjunction_test_cases[i].perform_test();
  }

  std::cout << std::endl;

  // TEST 1: disjunction.

  std::cout << "TEST 1 - DISJUNCTION" << std::endl;
  std::cout << "-----------------" << std::endl << std::endl;

  Simple_test disjunction_test_cases[4] = {
    Simple_test( { P, P }, P, disjunction, disjunction_print),
    Simple_test( { P, O }, O, disjunction, disjunction_print),
    Simple_test( { O, P }, O, disjunction, disjunction_print),
    Simple_test( { O, O }, O, disjunction, disjunction_print),
  };

  for (int i = 0 ; i < 4 ; ++i) {
    disjunction_test_cases[i].perform_test();
  }

  std::cout << std::endl;

  // TEST 1: implication.

  std::cout << "TEST 1 - IMPLICATION" << std::endl;
  std::cout << "-----------------" << std::endl << std::endl;

  Simple_test implication_test_cases[4] = {
    Simple_test( { P, P }, P, implication, implication_print),
    Simple_test( { P, O }, O, implication, implication_print),
    Simple_test( { O, P }, P, implication, implication_print),
    Simple_test( { O, O }, P, implication, implication_print),
  };

  for (int i = 0 ; i < 4 ; ++i) {
    implication_test_cases[i].perform_test();
  }

  std::cout << std::endl;
}

Player negation(std::vector<Player> input)
{
  return neg(input[0]);
}

void negation_print(std::vector<Player> input, Player output)
{
  std::cout << "¬"
            << player_char(input[0])
            << " = "
            << player_char(output);
}

Player conjunction(std::vector<Player> input)
{
  return conj(input[0], input[1]);
}

void conjunction_print(std::vector<Player> input, Player output)
{
  std::cout << player_char(input[0])
            << " ^ "
            << player_char(input[1])
            << " = "
            << player_char(output);
}

Player disjunction(std::vector<Player> input)
{
  return disj(input[0], input[1]);
}

void disjunction_print(std::vector<Player> input, Player output)
{
  std::cout << player_char(input[0])
            << " v "
            << player_char(input[1])
            << " = "
            << player_char(output);
}

Player implication(std::vector<Player> input)
{
  return impl(input[0], input[1]);
}

void implication_print(std::vector<Player> input, Player output)
{
  std::cout << player_char(input[0])
            << " => "
            << player_char(input[1])
            << " = "
            << player_char(output);
}



