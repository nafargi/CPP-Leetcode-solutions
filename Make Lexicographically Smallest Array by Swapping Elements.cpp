#include <ranges>

static auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
  vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
    auto sorted_nums = nums;
    sort(begin(sorted_nums), end(sorted_nums));

    auto chunks = sorted_nums
        | views::chunk_by([limit](auto a, auto b) { return b - a <= limit; });

    auto chunk_its_view =  chunks |
        views::transform([](auto chunk) { return begin(chunk); });
    auto chunk_its = vector(begin(chunk_its_view), end(chunk_its_view));

    auto chunk_fronts = chunks |
        views::transform([](auto chunk) { return chunk.front(); });
    auto chunk_lookup = vector(begin(chunk_fronts), end(chunk_fronts));

    for (auto& num : nums) {
      auto lut_it = prev(ranges::upper_bound(chunk_lookup, num));
      auto& chunk_it = chunk_its[distance(begin(chunk_lookup), lut_it)];
      num = *chunk_it++;
    }
    return nums;
  }
};
