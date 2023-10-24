using System;
using System.Collections.Generic;

namespace Aircompany.Planes
{
    public abstract class Plane
    {


        private string Model;
        private int _maxSpeed;
        private int _maxFlightDistance;
        private int _maxLoadCapacity;

        public Plane(string model, int maxSpeed, int maxFlightDistance, int maxLoadCapacity)
        {
            Model = model;
            _maxSpeed = maxSpeed;
            _maxFlightDistance = maxFlightDistance;
            _maxLoadCapacity = maxLoadCapacity;
        }

        public string GetModel()
        {
            return Model;
        }

        public int GetMS()
        {
            return _maxSpeed;
        }

        public int MaxFlightDistance()
        {
            return _maxFlightDistance;
        }

        public int MaxLoadCapacity()
        {
            return _maxLoadCapacity;
        }

        public override string ToString()
        {
            return $"Plane{{ model='{Model}', maxSpeed={_maxSpeed}, maxFlightDistance={_maxFlightDistance}, maxLoadCapacity={_maxLoadCapacity} }}";
        }

        public override bool Equals(object obj)
        {
            if (obj == null || GetType() != obj.GetType()) return false;
            Plane other = (Plane)obj;
            return Model == other.Model &&
                   _maxSpeed == other._maxSpeed &&
                   _maxFlightDistance == other._maxFlightDistance &&
                   _maxLoadCapacity == other._maxLoadCapacity;
        }

        public override int GetHashCode()
        {

            return HashCode.Combine(Model, _maxSpeed, _maxFlightDistance, _maxLoadCapacity);
        }        

    }
}
