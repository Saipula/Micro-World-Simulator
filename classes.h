// ---------------------------------------------------------------------------

#ifndef WorldH
#define WorldH
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <ctime>
#include <vector>

// ---------------------------------------------------------------------------
class World {
private:
	TCanvas *device;

	static const short w = 20, h = 16;
	short size;

	class Object {
		void draw(int col1, int col2);

		TCanvas *device;
		short size;

	protected:
		int col1, col2;

	public:
		int x, y;
		short type;
		bool isNew;

		Object(TCanvas *canv, short x, short y, short size);

		void hide() {
			draw(clWhite, clWhite);
		}

		void show() {
			draw(col1, col2);
		}
	};

	class Green : public Object {
	public:
		Green(TCanvas *canv, short x, short y, short size)
			: Object(canv, x, y, size) {
			col1 = clGreen;
			type = 1;
		};
	};

	class Yellow : public Object {
	public:
		Yellow(TCanvas *canv, short x, short y, short size)
			: Object(canv, x, y, size) {
			col1 = clYellow;
			type = 2;
		};
	};

	class Red : public Object {
	public:
		Red(TCanvas *canv, short x, short y, short size)
			: Object(canv, x, y, size) {
			col1 = clRed;
			type = 3;
		};
	};

	std::vector<Object*>arr;

	void create();
	void hide();

	void redraw() {
		hide();
		show();
	}

public:
	World(TCanvas *canv);
	void show();
	void live();
};

#endif
