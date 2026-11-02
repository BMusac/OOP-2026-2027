#include <cassert>
#include <iostream>
#include <algorithm>

class Volume {
	int vol;
	int before_mute;
	static int clamp(int l) {
		if (l < 0) {
			return 0;
		}if (l > 100) {
			return 100;
		}
		return l;
	};
public:
	Volume(int v = 50) {
		if (v > 100) {
			vol = 100;
		}
		else if (v < 0) {
			vol = 0;
		}
		else {
			vol = v;
		}
	}

	int get() {
		return vol;
	}
	void up(int v = 10) {
		vol = clamp(vol + v);
		assert(valid());

	}
	void mute() {
		before_mute = vol;
		vol = 0;
	}
	void unmute() {
		vol = before_mute;
	}
	void down(int v = 10) {
		vol = clamp(vol - v);
		assert(valid());
	}
private:
	bool valid() const {
		return vol >= 0 and vol <= 100;
	}
};


int main()
{
	Volume v;
	std::cout << v.get() << '\n';
	v.up();
	v.up(60);
	std::cout << v.get() << '\n';
	v.mute();
	std::cout << v.get() << '\n';
	v.unmute();
	std::cout << v.get() << '\n';
	Volume w(-20);
	w.down();
	std::cout << w.get() << '\n';
	return 0;
}

/*
Ocekivani ispis:

	50
	100
	0
	100
	0
*/
