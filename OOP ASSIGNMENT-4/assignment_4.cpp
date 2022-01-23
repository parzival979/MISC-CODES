//INCLUDING THE STANDARD LIBRARY
#include <iostream>

//AREA CLASS
class area{
//PRIVATE ACCESS SPECIFIER FOR THE ATTRIBUTES
private:
    double length,breadth,radius;
//PUBLIC ACCESS SPECIFIER FOR THE METHODS
public:
    //FRIEND FUNCTIONS
    friend inline double rectangle(area a);
    friend inline double circle(area a);
    //PARAMETERIZED CONSTRUCTOR
    area(double length1=1,double breadth1=1,double radius1=1){
        length=length1;
        breadth=breadth1;
        radius=radius1;
    }
};

//INLINE FRIEND FUNCTIONS TO FIND AREAS OF RECTNAGLE AND CIRCLE
inline double rectangle(area a){
    return(a.length*a.breadth);
}
inline double circle(area a){
    return(3.141592654*(a.radius*a.radius));
}

//VOLUME CLASS
class volume{
//PRIVATE ATTRIBUTES
private:
    double length,breadth,height,radius;
//PUBLIC MEMBER FUNCTIONS
public:
    //PARAMETERIZED CONSTRUCTOR
    volume(double length1=1,double breadth1=1,double height1=1,double radius1=1){
        length=length1;
        breadth=breadth1;
        height=height1;
        radius=radius1;
    }
    //FUNCTION TO FIND VOLUME OF THE CUBOID
    inline double cuboid(){
        area a(length,breadth);
        return (rectangle(a)*height);
    }
    //FUNCTION TO FIND VOLUME OF THE SPHERE
    inline double sphere(){
        area a(1,1,radius);
        return (circle(a)*1.3333*radius);
    }
    //FUNCTION TO COMPARE VOLUMES OF TWO CUBOIDS
    void compareCuboid(double length1=1,double breadth1=1,double height1=1){
        volume v(length1,breadth1,height1);
        if(v.cuboid()>this->cuboid()){
            std::cout<<"THE LATTER CUBOID HAS MORE VOLUME\n";
        }
        else if(v.cuboid()< this->cuboid()){
            std::cout<<"THE LATTER CUBOID HAS LESS VOLUME\n";
        }
        else{
            std::cout<<"BOTH FIGURES HAVE THE SAME AREA\n";
        }
    }
    //FUNCTION TO COMPARE VOLUMES OF TWO SPHERES
    void compareSphere(double radius1=1){
        volume v(1,1,1,radius1);
        if(v.sphere()> this->sphere()){
            std::cout<<"THE LATTER SPHERE HAS MORE VOLUME\n";
        }
        else if(v.sphere()<this->sphere()){
            std::cout<<"THE LATTER SPHERE HAS LESS VOLUME\n";
        }
        else{
            std::cout<<"BOTH THE FIGURES HAVE THE SAME AREA\n";
        }
    }
};

int main(void){
    //MENU DRIVEN PROGRAM TO FIND AREA AND VOLUME
    while(true){
        std::cout<<"ENTER 1 FOR AREA,2 FOR VOLUME,3 TO EXIT THE PROGRAM\n";
        int menuOption;
        std::cin>>menuOption;
        if(menuOption==1){
            std::cout<<"ENTER 1 FOR AREA OF RECTANGLE,2 FOR AREA OF CIRCLE\n";
            int internalMenuOption;
            std::cin>>internalMenuOption;
            if(internalMenuOption==1){
                double length,breadth;
                std::cout<<"PLEASE ENTER THE LENGTH OF THE RECTANGLE\n";
                std::cin>>length;
                std::cout<<"PLEASE ENTER THE BREADTH OF THE RECTANGLE\n";
                std::cin>>breadth;
                area a(length,breadth);
                std::cout<<"THE AREA OF THE RECTANGLE IS "<<rectangle(a)<<"\n";
            }
            else if(internalMenuOption==2){
                double radius;
                std::cout<<"PLEASE ENTER THE RADIUS OF THE CIRCLE\n";
                std::cin>>radius;
                area a(1,1,radius);
                std::cout<<"THE AREA OF THE CIRCLE IS "<<circle(a)<<"\n";
            }
            else{
                std::cout<<"PLEASE ENTER THE CORRECT OPTION\n";
            }
        }
        else if(menuOption==2){
            std::cout<<"ENTER 1 FOR VOLUME OF CUBOID,ENTER 2 FOR VOLUME OF SPHERE\n";
            int internalMenuOption;
            std::cin>>internalMenuOption;
            if(internalMenuOption==1){
                double length,breadth,height;
                std::cout<<"PLEASE ENTER THE LENGTH OF THE CUBOID\n";
                std::cin>>length;
                std::cout<<"PLEASE ENTER THE BREADTH OF THE CUBOID\n";
                std::cin>>breadth;
                std::cout<<"PLEASE ENTER THE HEIGHT OF THE CUBOID\n";
                std::cin>>height;
                volume v(length,breadth,height);
                std::cout<<"THE VOLUME OF CUBOID IS "<<v.cuboid()<<"\n";
                std::cout<<"ENTER 1 TO COMPARE THE VOLUME OF ANOTHER CUBOID,ELSE ANY OTHER NUMBER\n";
                int compareOption;
                std::cin>>compareOption;
                if(compareOption==1){
                    std::cout<<"PLEASE ENTER THE LENGTH OF THE CUBOID\n";
                    std::cin>>length;
                    std::cout<<"PLEASE ENTER THE BREADTH OF THE CUBOID\n";
                    std::cin>>breadth;
                    std::cout<<"PLEASE ENTER THE HEIGHT OF THE CUBOID\n";
                    std::cin>>height;
                    v.compareCuboid(length,breadth,height);
                }

            }
            else if(internalMenuOption==2){
                double radius;
                std::cout<<"PLEASE ENTER THE RADIUS OF THE SPHERE\n";
                std::cin>>radius;
                volume v(1,1,1,radius);
                std::cout<<"THE VOLUME OF THE SPHERE IS "<<v.sphere()<<"\n";
                std::cout<<"ENTER 1 TO COMPARE THE VOLUME OF ANOTHER SPHERE,ELSE ANY OTHER NUMBER\n";
                int compareOption;
                std::cin>>compareOption;
                if(compareOption==1){
                    std::cout<<"PLEASE ENTER THE RADIUS OF THE SPHERE\n";
                    std::cin>>radius;
                    v.compareSphere(radius);
                }
            }

        }
        else if(menuOption==3){
            break;
        }
        else{
            std::cout<<"PLEASE ENTER THE CORRECT OPTION\n";
        }
    }

}