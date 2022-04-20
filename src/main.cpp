#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	const auto Pi = atan2(0, -1);

	int n;
	cin >> n;
	while (0 < (n--)) {
		double t, x;
		cin >> t >> x;

		t *= 100;
		const auto& rad = x * Pi / 180;
		const auto& m = tan(rad);
		const auto& base = sqrt(m * m + 1);

		const auto& d0 = (-m * t) / base;
		if (abs(d0) <= 16) {
			cout << "yes\n";
			continue;
		}

		auto dnow = d0;
		auto y = double{ 0 };
		auto isHit = bool{ false };
		while (0 < dnow * d0) {
			y += 85;
			dnow = (-m * t + y) / base;
			if (abs(dnow) <= 16) {
				cout << "yes\n";
				isHit = true;
				break;
			}
		}

		if (!isHit) {
			cout << "no\n";
		}
	}

	return 0;
}