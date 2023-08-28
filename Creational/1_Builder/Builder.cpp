/*
* The Builder pattern is used for creation of complicated objects,
* which cannot be constructed using single line constructor call.
*/

/*
* The Builder pattern is concerned with the creation of complicated objects,
* that is, objects that cannot be built up in a single - line constructor call.
* These types of objects may themselves be composed of other objects and
* might involve less - than - obvious logic, necessitating a separate component
* specifically dedicated to object construction.
*/

#include <iostream>
#include <memory>

using namespace std;
class Product;

// Builder interface
class Builder
{
public:
  virtual ~Builder() {}
  virtual void buildPartA() = 0;
  virtual void buildPartB() = 0;
  virtual void buildPartC() = 0;
  virtual unique_ptr<Product> getProduct() = 0;
};

// Concrete builder
class ConcreteBuilder : public Builder
{
public:
  void buildPartA() override {
    cout << "Building part A" << endl;
  }

  void buildPartB() override {
    cout << "Building part B" << endl;
  }

  void buildPartC() override {
    cout << "Building part C" << endl;
  }

  unique_ptr<Product> getProduct() override {
    return make_unique<Product>();
  }
};

// Product
class Product {
public:
  void print() {
    cout << "Product created" << endl;
  }
};

// Director
class Director {
public:
  void construct(Builder* builder) {
    builder->buildPartA();
    builder->buildPartB();
    builder->buildPartC();
  }
};

int main()
{
  Director director;
  auto concrete_builder_ptr = std::make_unique<ConcreteBuilder>();
  Builder* builder = concrete_builder_ptr.get();
  director.construct(builder);
  unique_ptr<Product> product = builder->getProduct();
  product->print();
  return 0;
}