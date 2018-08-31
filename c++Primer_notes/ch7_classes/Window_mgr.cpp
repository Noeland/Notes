#include <iostream>
#include <string>
#include <vector>

class Screen;

class Window_mgr{
public:
  using ScreenIndex = std::vector<Screen>::size_type;
  Window_mgr();
  void clear(ScreenIndex);
  
private:
  std::vector<Screen> screens;
};

class Screen {

  friend void Window_mgr::clear(ScreenIndex);
public:
  typedef std::string::size_type pos;
  Screen() = default;
  Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(wd*ht, c) { }
  Screen(pos ht, pos wd): height(ht), width(wd), contents(ht*wd, ' ') { }

  char get() const
  { return contents[cursor]; }
  
  inline char get(pos r, pos c) const;
  Screen &move(pos r, pos c);
  Screen &set(char);
  Screen &set(pos, pos, char);
  Screen &display(std::ostream& os)
  { do_display(os); return *this; } 
  const Screen &display(std::ostream& os) const
  { do_display(os); return *this; }

private:
  void do_display(std::ostream& os) const { os << contents; }
 
  mutable size_t screen_ctr;
  pos cursor = 0;
  pos height = 0, width = 0;
  std::string contents;
};

inline
Screen &Screen::move(pos r, pos c)
{
  pos row = r * width;
  cursor = row + c;
  return *this;
}

char Screen::get(pos r, pos c) const
{
  pos row = r * width;
  return contents[row + c];
}

inline Screen &Screen::set(char c)
{
  contents[cursor] = c;
  return *this;
}

inline Screen &Screen::set(pos r, pos col, char c)
{
  contents[r * width + col] = c;
  return *this;
}

Window_mgr::Window_mgr()
{
  screens.push_back(Screen(24, 80, ' '));
}

void Window_mgr::clear(ScreenIndex i)
{
  Screen &s = screens[i];
  s.contents = std::string(s.height * s.width, ' ');
}

int main()
{

}
