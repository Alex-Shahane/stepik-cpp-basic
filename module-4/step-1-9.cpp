#include <iostream>

struct Foo {
	void say() const { 
		std::cout << "Foo says: " << msg << "\n";
	}

protected:
	Foo(const char* msg)
		: msg(msg) {
	}

private:
	const char* msg;
};

struct Foo2 : Foo {
	Foo2(const char* msg)
		: Foo(msg) {
	}
};

void foo_says(const Foo& foo) { 
	foo.say(); 
}

Foo2 get_foo(const char* msg) {
	return Foo2(msg);
};

int main() {
	foo_says(get_foo("Hello!"));
}
