#pragma once

#include "bits/stdc++.h"

using namespace std;
#define LOCAL
using namespace std;
template<class c>
struct rge
{
  c b, e;
};

template<class c>
rge<c> range(c i, c j)
{
  return rge<c>{i, j};
}
template<class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template<class c>
char dud(...);

struct debug
{
#ifdef LOCAL
  ~debug()
  {
    cerr << endl;
  }
  template<class c>
  typename enable_if<sizeof dud<c>(0) != 1, debug&>::type operator<<(c i)
  {
    cerr << boolalpha << i;
    return *this;
  }
  template<class c>
  typename enable_if<sizeof dud<c>(0) == 1, debug&>::type operator<<(c i)
  {
    return *this << range(begin(i), end(i));
  }
  template<class c, class b>
  debug& operator<<(pair<b, c> d)
  {
    return *this << "(" << d.first << ", " << d.second << ")";
  }
  template<class c>
  debug& operator<<(rge<c> d)
  {
    *this << "[";
    for (auto it = d.b; it != d.e; ++it)
      *this << ", " + 2 * (it == d.b) << *it;
    return *this << "]";
  }
  template<template<class...> class c, class... Args>
  debug& operator<<(vector<c<Args...>> v)
  {
    *this << "[\n";
    for (auto e : v)
      *this << "   " << range(begin(e), end(e)) << "\n";
    return *this << "]";
  }
#else
  template<class c>
  debug& operator<<(const c&)
  {
    return *this;
  }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto& it : a)
#define PI 3.1415926535897932384626

using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;
using pii = pair<int, int>;
using pl = pair<ll, ll>;
using vc = vector<char>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pii>;
using vpl = vector<pl>;
using vvi = vector<vi>;
using vvc = vector<vc>;
using vvl = vector<vl>;

using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using f32 = float;
using f64 = double;

template<typename T>
using Solution = std::pair<T, T>;

namespace aoc::utils
{

std::pair<std::string, std::string> split_line(std::string const& str, const char* delimiter);

} // namespace aoc::utils
