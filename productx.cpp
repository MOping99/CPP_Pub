// MCS 360 Project Two by <Mikael & Victor>

#include "productx.h"

Product::Product(){
	return Monomial();
};

Product::Product(Monomial mono){
	prod.push_back(mono);
};

Product::Product(Product pro){
	prod = pro;
};

Product::size(){
	return prod.size()
};

Product::operatorMult(Monomial mono){
	Product newProduct = Product();
	for (Monomial m :: prod){
		int temp = m.power() + mono.power();
		newProduct.push_back(Monomial("x", temp));
	}

	return newProduct;
};

Product::operatorMult(Product pro){
	Product newProduct = Product();
	for (Monomial m :: prod){
		for( Monomial n :: pro){
			int temp = m.power() + n.power();
			newProduct.push_back(Monomial("x", temp));
		}

	}

	return newProduct;
};

Product::operator(double doub){
	double answer;
	int count = 0;

	for (Monomial m :: prod){
		double temp = m.operator(doub)

		if (count == 0){
			answer = temp;
			count++;
		}

		else{
			answer = answer * temp;
		}

	}

	return answer;
};

/*
int main(){

  Product prod1;
  Monomial x;
  Product prod2 = Product(x);
  Product prod3 = Product(prod2);

  list<Monomial> p = prod3.remember();

  cout << p.size();

  prod1.get_size(); prod2.get_size(); prod3.get_size();

  return 0;
}
*/
