
class MPoint
{
public:
	double x, y;
	
public:
	MPoint(double _x,double _y) {
		x = _x;
		y = _y;
	}
	MPoint(CPoint p) {
		x = p.x;
		y = p.y;
	}
	inline MPoint operator =(MPoint p) {
		x = p.x;
		y = p.y;
		return (*this);
	}
	inline MPoint operator =(CPoint p) {
		x = p.x;
		y = p.y;
		return (*this);
	}
	inline MPoint operator +=(MPoint p) {
		x += p.x;
		y += p.y;
		return (*this);
	}
	inline MPoint operator +=(CPoint p) {
		x += p.x;
		y += p.y;
		return (*this);
	}
	inline MPoint operator -=(MPoint p) {
		x -= p.x;
		y -= p.y;
		return (*this);
	}
	inline MPoint operator -=(CPoint p) {
		x -= p.x;
		y -= p.y;
		return (*this);
	}
	inline MPoint operator *=(double s) {
		x *= s;
		y *= s;
		return (*this);
	}
	inline MPoint operator /=(double s) {
		x /= s;
		y /= s;
		return (*this);
	}
	inline MPoint operator +(MPoint p) {
		MPoint t;
		t.x = x + p.x;
		t.y = y + p.y;
		return (t);
	}
	inline MPoint operator +(CPoint p) {
		MPoint t;
		t.x = x + p.x;
		t.y = y + p.y;
		return (t);
	}
	inline MPoint operator -(MPoint p) {
		MPoint t;
		t.x = x - p.x;
		t.y = y - p.y;
		return (t);
	}
	inline MPoint operator -(CPoint p) {
		MPoint t;
		t.x = x - p.x;
		t.y = y - p.y;
		return (t);
	}
	inline MPoint operator *(double s) {
		MPoint t;
		t.x = x *s;
		t.y = y *s;
		return (t);
	}
	inline MPoint operator /(double s) {
		MPoint t;
		t.x = x /s;
		t.y = y /s;
		return (t);
	}
	inline operator CPoint() {
		return CPoint((int)x, (int)y);
	}
	MPoint();
	~MPoint();
};
