#include <ncurses.h>

int main() {
  int ch;

  initscr();
  raw();
  keypad(stdscr, TRUE);
  noecho();
  printw("SKriv noe: ");
  ch = getch();

  if (ch == KEY_F(2)) {
    printw("Du trykket F2");
  } else {
    printw("Du trykket ");
    attron(A_BOLD);
    printw("%c", ch);
    attroff(A_BOLD);
  }
  refresh();
  getch();
  endwin();

  return 0;
}
