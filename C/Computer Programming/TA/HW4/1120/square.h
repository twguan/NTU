class Square{
	public:
		Square();
		Square(int n);
		int area();
		int getLen();
		void setLen(int n);
		friend int cmpSquare(Square &s1, Square &s2);
	private:
		int Length;
};
