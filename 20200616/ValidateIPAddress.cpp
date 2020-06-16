class Solution {
public:
    string validIPAddress(string IP) {
        // Start 15:10 - 16:25
        // Google convert HEX string to int 16:05 - 16:08
        // using input string stream istringstream and std::hex
        if (isV4(IP))
        {
            return "IPv4";
        }
        else if (isV6(IP))
        {
            return "IPv6";
        }
        else
        {
            return "Neither";
        }
    }

    bool isV4(string IP)
    {
        // Check num dots
        if (count(begin(IP), end(IP), '.') != 3) return false;

        // Check each field
        size_t i{0}, j{0};
        size_t nFields{0};
        while (i < IP.size())
        {
            auto it = find(begin(IP) + i, end(IP), '.');
            j = it - begin(IP);
            auto field = IP.substr(i, j - i);
            if (!field.empty()) nFields++;

            // Check field non-empty
            if (i == j) return false; // field.size() = IP.size() - i

            // Check leading zero
            if (field.size() > 1 && field[0] == '0') return false;

            // Check max length
            if (field.size() > 3) return false;

            // Check is decimal digit
            if(!all_of(begin(field), end(field), ::isdigit)) return false;

            // Check within 0-255
            if (stoi(field) > 255) return false;

            i = j + 1;
        }
        if (nFields != 4) return false;

        return true;
    }

    bool isV6(string IP)
    {
        // Check num colons
        if (count(begin(IP), end(IP), ':') != 7)
        {
            return false;
        }

        // Check each field
        size_t i{0}, j{0};
        size_t nFields{0};
        while (i < IP.size())
        {
            auto it = find(begin(IP) + i, end(IP), ':');
            j = it - begin(IP);
            auto field = IP.substr(i, j - i);
            if (!field.empty()) nFields++;

            // Check omit field
            if (i == j) {
                return false;
            }

            // Check extra length
            if (field.size() > 4)
            {
                return false;
            }

            // Check if all of field is hex digits
            if (!all_of(begin(field), end(field), ::isxdigit)) return false;

            // Check hex within 16 bit
            int x;
            if (istringstream(field) >> std::hex >> x && x > 0xFFFF) return false;
            i = j + 1;
        }
        if (nFields != 8) return false;
        return true;
    }
};
