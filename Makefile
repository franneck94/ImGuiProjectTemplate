all: prepare

install_min:
	sudo apt-get install gcc g++ cmake make doxygen

install: install_min
	sudo apt-get install git llvm pkg-config curl zip unzip tar python3-dev clang-format clang-tidy cppcheck iwyu

install_pip:
	pip install jinja2 Pygments cmake-format pre-commit

install_doc: install_min
	sudo apt-get install doxygen
	pip install jinja2 Pygments

prepare:
	rm -rf build
	mkdir build
