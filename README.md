# Qt-5-Cpp2
Repositorie created to help during the course 'Qt 5 C++ GUI Development For Beginners : The Fundamentals'.

We will create a class that will calculate the *area* of a rectangular parallelepiped.

![image](https://user-images.githubusercontent.com/58916022/223706846-745685a3-99ce-4544-b3a9-87dfe8499a2a.png)

Note: Method is the correct name of the function when the function is located inside a class/object.

# C++ Classes

After creating a new project, same configuration as used in [Qt-5-Cpp1](https://github.com/Rafaelatff/Qt-5-Cpp1), we will start by creating a class type.

# Simple declaraction of a class type

The following code, will generate a class, that has private member variables and some public methods. 

```c++
class Rectangle{
public:
    void setWidth(uint32_t width){
        this->width = width; //object of this class
    }
    void setLength(uint32_t length){
        this->length = length;
    }
    int getArea(){
        return width * length;
    }

private:
    uint32_t width;
    uint32_t length;
};
```

In the main(), we create a variable member with class type **Rectangle**, and call it **r**.

```c++
    Rectangle r;
    r.setWidth(10);
    r.setLength(20);
    cout << "The area of the rectangle is:" << r.getArea() << endl;
```

As result, we have:

![image](https://user-images.githubusercontent.com/58916022/223698545-ef20509b-20da-4887-b288-b48ef71588e4.png)

If we change the methods from **public** to **private** we will have the following error:

![image](https://user-images.githubusercontent.com/58916022/223699603-1e880f1e-10cb-4062-b27e-979e5e488579.png)

We cannot call the methods from the main function, when it's a private variable.

# Declaring the methods outside the class

The correct way of creating a class, is to call the methods inside the class but declare those outside, as we can see next:

```c++
class Rectangle{
public:
    void setWidth(uint32_t width);
    void setLength(uint32_t length);
    int getArea(){
        return width * length;
    }

private:
    uint32_t width;
    uint32_t length;
};

void Rectangle::setWidth(uint32_t width){
    this->width = width; //object of this class
}

void Rectangle::setLength(uint32_t length){
    this->length = length;
}
```

We will have the same result as before.

## Adding constructor for our class type

Adding constructors from our class we can set the variable member values inside the class. The default constructor always have the same name as the class. The code for the defaut constructor is showed next:

```c++
class Rectangle{
public:
    Rectangle();
    ...
}

// Then outside the class
Rectangle::Rectangle(){
    clog << "Default Constructor called" << endl;
    this->length = 5;
    this->width = 5;
}  

// Lets just create a class type with name r
int main()
{
    Rectangle r;
    cout << "The area of the rectangle is:" << r.getArea() << endl;
    return 0;
}
```
And we will have as result:

![image](https://user-images.githubusercontent.com/58916022/223703715-7d905a14-d400-4c55-bdbd-4d005c1b8149.png)

Now let's create a new constructor:

```c++
class Rectangle{
public:
    // Constructor
    Rectangle(); // Default constructor
    Rectangle (uint32_t w, uint32_t l);
    ...
}

// Then outside the class
Rectangle::Rectangle (uint32_t w, uint32_t l){
    clog << "Custom Constructor called" << endl;
    this->length = w;
    this->width = l;
}

// And for the main:
int main()
{
    Rectangle r;
    Rectangle r1(20,20);
    cout << "The area of the rectangle is:" << r1.getArea() << endl;
    return 0;
}
```
As result we have:

![image](https://user-images.githubusercontent.com/58916022/223704249-32734d11-ad2d-456e-9b48-3427a31b9133.png)

## Creating initializer list for our class type

The initializer list , you past the initiaze code to initialize your member variables just after the parameter list of your constructor.

We commented our previous custom constructor and then recreate it as the following way:

```c++
Rectangle::Rectangle (uint32_t w, uint32_t l):width(w),length(l){
    clog << "Custom Constructor called" << endl;
}
```
## Creating the para class obj to calculate volume

The para class will call the previous created class object to calculate the area of the rectangular parallelepiped.

For that, we just add the class object with the name para, and add a member variable with the name height.

```c++
class Para{
public:
    Para(uint32_t w,uint32_t l, uint32_t h):r(w,l),height(h){
        cout << "Para Constructor Called" << endl;
    }
    uint32_t getVolume(){
        return r.getArea() * height;
    }
private:
    Rectangle r;
    uint32_t height;
};
```

At main, we just add the lines: 

```c++
    Para p (30,30,30);   
    cout << "The volume of our shape is:" << p.getVolume() << endl;
```
And as result, we have a volume of 27000 (that is 30 * 30 * 30).

![image](https://user-images.githubusercontent.com/58916022/223709621-da70e488-50f7-4ac8-87e0-f72b280e7131.png)

## Inheritance between object classes

Here we will have a class that extends the rectangle and inherit everything from the public space of the rectangle class.

```c++
class Square: public Rectangle{
public:
    Square(uint32_t side):Rectangle(side,side){
    }
 };
```

Then the main just stayed as:

```c++
int main(){
    Rectangle r;
    Rectangle r1(20,20);
    Para p (30,30,30);
    Square s(40);
    cout << "The area of the rectangle is:" << r1.getArea() << endl;
    cout << "The volume of our shape is:" << p.getVolume() << endl;
    cout << "The area of our square is:" << s.getArea() << endl;
    return 0;
}
```

And we have as result:

![image](https://user-images.githubusercontent.com/58916022/223712650-ec4a2169-2f20-4f13-8bd8-66c08e694a29.png)

## Separing the files

Now we will create new header and source files for each class that we created. Then we will move the class object for the header file and everything that is outside to the source file.


