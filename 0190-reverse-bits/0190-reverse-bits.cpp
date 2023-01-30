class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        std::string s = std::bitset< 32 >( n ).to_string();
        reverse(s.begin(),s.end());
        return static_cast<uint32_t>(std::bitset<32>(s).to_ulong());
    }
};