#include <vector>

using std::vector;

bool binSearch(const vector<int> &text, const int &sought)
{
  // beg and end are the range of our search
  // end is a iterator pointing to the position after the last element of current search
  // end itself points to an element that is not in the range of our search
  // so if beg is equal to end, we have nothing to search any more.
  auto beg = text.cbegin();
  auto end = text.cend();
  auto mid = text.cbegin() + (end - beg)/2;

  while(beg < end && *mid != sought)
    {
      if(*mid < sought)
	beg = mid+1;
      else
	end = mid;
      mid = beg + (end - beg)/2;
    }

  return sought == *mid;
}

int main()
{

}
