#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

enum Player
{
  O = 'O',
  P = 'P'
};

Player neg(Player b)
{
  if (b == P)
  {
    return O;
  }
  else
  {
    return P;
  }
}

inline Player conj(Player b, Player c)
{
  if ((b == P) && (c == P))
  {
    return P;
  }
  else
  {
    return O;
  }
}

inline Player disj(Player b, Player c)
{
  if ((b == P) || (c == P))
  {
    return P;
  }
  else
  {
    return O;
  }
}

inline Player impl(Player b, Player c)
{
  return (disj(neg(b), c));
}

char player_char(Player b)
{
  if (b == P)
  {
    return('P');
  }
  else
  {
    return('O');
  }
}


#endif
