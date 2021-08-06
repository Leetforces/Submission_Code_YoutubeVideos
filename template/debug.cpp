template <typename A, typename B>
ostream &operator<<(ostream &out, const pair<A, B> &a)
{
  out << "(" << a.first << "," << a.second << ")";
  return out;
}
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &a)
{
  out << "[";
  bool first = true;
  for (auto &v : a)
  {
    out << (first ? "" : ", ");
    out << v;
    first = 0;
  }
  out << "]";
  return out;
}
template <typename T, class Cmp>
ostream &operator<<(ostream &out, const set<T, Cmp> &a)
{
  out << "{";
  bool first = true;
  for (auto &v : a)
  {
    out << (first ? "" : ", ");
    out << v;
    first = 0;
  }
  out << "}";
  return out;
}
template <typename T, class Cmp>
ostream &operator<<(ostream &out, const unordered_set<T, Cmp> &a)
{
  out << "{";
  bool first = true;
  for (auto &v : a)
  {
    out << (first ? "" : ", ");
    out << v;
    first = 0;
  }
  out << "}";
  return out;
}
template <typename U, typename T, class Cmp>
ostream &operator<<(ostream &out, const map<U, T, Cmp> &a)
{
  out << "{";
  bool first = true;
  for (auto &p : a)
  {
    out << (first ? "" : ", ");
    out << p.first << ":" << p.second;
    first = 0;
  }
  out << "}";
  return out;
}
template <typename U, typename T, class Cmp>
ostream &operator<<(ostream &out, const unordered_map<U, T, Cmp> &a)
{
  out << "{";
  bool first = true;
  for (auto &p : a)
  {
    out << (first ? "" : ", ");
    out << p.first << ":" << p.second;
    first = 0;
  }
  out << "}";
  return out;
}
template <typename U, typename T, class Cmp>
ostream &operator<<(ostream &out, const multimap<U, T, Cmp> &a)
{
  out << "{";
  bool first = true;
  for (auto &p : a)
  {
    out << (first ? "" : ", ");
    out << p.first << ":" << p.second;
    first = 0;
  }
  out << "}";
  return out;
}
#ifndef LOCAL
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 17
#endif
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
   cerr << name << ": " << arg1 <<"\n";
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
  const char *comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " | ";
  __f(comma + 1, args...);
}

