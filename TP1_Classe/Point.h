class Point
{
	double x;
	double y;
	public:
	// Exo1
	void afficher();
	// Exo2
	void saisir();
	// Exo3 a
	Point(double a, double b);
	// Exo3 b
	Point();
	// Exo4
	double distance(Point & P);
	// Exo5 : cette fonction ne fait pas partie de la classe Point
	// Exo6 : même question que Exo2
	// Exo7 : cette fonction ne fait pas partie de la classe Point
	// Exo8 : cette fonction ne fait pas partie de la classe Point
	//
};

// Exo5
void afficher(Point *T, int N);

// Exo7
void  saisir(Point *T, int N);

// Exo8
Point *saisir_points(int &n);




