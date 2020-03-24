#include <iostream>

using namespace std;

class Vector3D
{
protected:
    double x;
    double y;
    double z;
public:
    // Конструкторы
    Vector3D(){};
    Vector3D(double x, double y, double z): x(x), y(y), z(z) {
    };

    // Деструктор
    ~Vector3D(){};

    // Получение координат
    double getX() const{
        return x;
    };
    double getY() const{
        return y;
    };

    double getZ() const{
        return z;
    };

    void setX(double x){
        this->x=x;
    };
    void setY(double y){
        this->y=y;
    };
    void setZ(double z){
        this->z=z;
    };

    Vector3D operator+ (const Vector3D& v2) const{
        return Vector3D(x + v2.x, y + v2.y, z + v2.z);
    };

    Vector3D operator- (const Vector3D& v2) const{
        return Vector3D(x - v2.x, y - v2.y, z - v2.z);
    };

    Vector3D operator* (const double a) const{
        return Vector3D(x*a , y*a, z*a);
    };

    double operator* (const Vector3D& v2) const{
        return x*v2.getX() + y*v2.getY() + z*v2.getZ();
    };
};

Vector3D operator* (double a, const Vector3D& v){
    return Vector3D(v.getX()*a, v.getY()*a, v.getZ()*a);
};

std::ostream& operator<<(std::ostream& os, const Vector3D& v) {
    os << "(" << v.getX() << "; " << v.getY() << "; " <<v.getZ() << ")";
    return os;
};

std::istream& operator>>(std::istream &is, Vector3D &v){
    double x, y, z;
    is >> x >> y >> z;
    v.setX(x);
    v.setY(y);
    v.setZ(z);
    return is;
};

class Matrix3D
{
protected:
    double data[9];
public:
    Matrix3D(){
    };

    Matrix3D(double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33){
         data[0]=(a11);
         data[1]=(a12);
         data[2]=(a13);
         data[3]=(a21);
         data[4]=(a22);
         data[5]=(a23);
         data[6]=(a31);
         data[7]=(a32);
         data[8]=(a33);
    };

    ~Matrix3D(){
    }

    double getM(int i, int j) const{
        return this->data[i*3+j];
    };

    void setM(int i, int j, double x){
        this->data[i*3+j]=x;
    };

    double det(){
        return this->data[0]*(this->data[4]*this->data[8]-this->data[5]*this->data[7])-data[1]*(this->data[3]*this->data[8]-this->data[5]*this->data[6])+data[2]*(this->data[3]*this->data[7]-this->data[4]*this->data[6]);
    };

    Matrix3D operator+ (const Matrix3D& m2) const{
        Matrix3D M;
        for (int i=0; i<3; i++)
        {
            for (int j=0; j<3; j++)
            {
                M.setM(i, j, this->data[i*3+j]+m2.getM(i, j));
            }
        }
        return M;
    };

    Matrix3D operator- (const Matrix3D& m2) const{
        Matrix3D M;
        for (int i=0; i<3; i++)
        {
            for (int j=0; j<3; j++)
            {
                M.setM(i, j, this->data[i*3+j]-m2.getM(i, j));
            }
        }
        return M;
    };

    Matrix3D operator* (const double a) const{
        Matrix3D M;
        for (int i=0; i<3; i++)
        {
            for (int j=0; j<3; j++)
            {
                M.setM(i, j, this->data[i*3+j]*a);
            }
        }
        return M;
    };


    Matrix3D operator* (const Matrix3D& m2) const{
        Matrix3D M;
        for (int i=0; i<3; i++)
        {
            for (int j=0; j<3; j++)
            {
                double a=0;
                for (int k=0; k<3; k++)
                {
                    a+=this->data[i*3+k]*m2.getM(k, j);
                }
                M.setM(i, j, a);
            }
        }
        return M;
    };

    Vector3D operator* (const Vector3D& v) const{
        Vector3D V;
        double a=this->data[0]*v.getX()+this->data[1]*v.getY()+this->data[2]*v.getZ();
        double b=this->data[3]*v.getX()+this->data[4]*v.getY()+this->data[5]*v.getZ();
        double c=this->data[6]*v.getX()+this->data[7]*v.getY()+this->data[8]*v.getZ();
        V.setX(a);
        V.setY(b);
        V.setZ(c);
        return V;
    };
};

Matrix3D operator* (double a, const Matrix3D& m){
    Matrix3D M;
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            M.setM(i, j, m.getM(i, j)*a);
        }
    }
    return M;
};

std::ostream& operator<<(std::ostream& os, const Matrix3D& m) {
    os<<"(";
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            os<<m.getM(i, j);
            if ((i!=2) || (j!=2))
                os<<"; ";
        }
    }
    os << ")";
    return os;
};

std::istream& operator>>(std::istream &is, Matrix3D &m){
    double a[3][3];
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            is>>a[i][j];
        }
    }
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            m.setM(i, j, a[i][j]);
        }
    }
    return is;
};

int main()
{
    // Вектор задан в коде
    Vector3D A(1, 2, 3);
    // Вектор читается из cin
    Vector3D B;
    cin >> B;

    // Базовые операции с векторами
    cout << "A = " << A << endl;
    cout << "B = " << B << endl;
    cout << "A * 3 = " << A * 3 << endl;
    cout << "2 * B = " << 2 * B << endl;
    cout << "A + B = " << A + B << endl;
    cout << "A - B = " << A - B << endl;
    cout << "A * B = " << A * B << endl;

        // Матрица задана в коде
    Matrix3D C(1, 0, 0, 0, 2, 0, 0, 0, 3);
    // Матрица читается из cin
    Matrix3D D;
    cin >> D;

    // Базовые операции с матрицами
    cout << "C = " << C << endl;
    cout << "D = " << D << endl;
    cout << "C * 3 = " << C * 3 << endl;
    cout << "2 * D = " << 2 * D << endl;
    cout << "C + D = " << C + D << endl;
    cout << "C - D = " << C - D << endl;
    cout << "C * D = " << C * D << endl;

    // Детерминант матрицы
    cout << "det(D) = " << D.det() << endl;

    // Умножение матрицы на вектор
    cout << "D * B = " << D * B << endl;
    cout << "C * D = " << C * D << endl;
    return 0;
}
