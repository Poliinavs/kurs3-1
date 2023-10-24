using System;

namespace Aircompany.Planes
{
    public class PassengerPlane : Plane
    {
        private int PassengersCapacity; //был public
        public int PassengersCapacityIs()
        {
            return PassengersCapacity;
        }

        public PassengerPlane(string model, int maxSpeed, int maxFlightDistance, int maxLoadCapacity, int passengersCapacity)
            : base(model, maxSpeed, maxFlightDistance, maxLoadCapacity)
        {
            PassengersCapacity = passengersCapacity;
        }

        public override bool Equals(object obj)
        {
            if (obj == null || GetType() != obj.GetType()) return false;
            PassengerPlane other = (PassengerPlane)obj;
            return base.Equals(obj) && PassengersCapacity == other.PassengersCapacity;
        }

        public override int GetHashCode() //был свой
        {
            return HashCode.Combine(base.GetHashCode(), PassengersCapacity);
        }




        public override string ToString()
        {
            return base.ToString() + $", passengersCapacity={PassengersCapacity}";
        }       
        
    }
}
