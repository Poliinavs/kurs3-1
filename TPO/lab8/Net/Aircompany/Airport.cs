using Aircompany.Models;
using Aircompany.Planes;
using System;
using System.Collections.Generic;
using System.Linq;

namespace Aircompany
{
    public class Airport
    {
        public List<Plane> Planes { get; }

        public Airport(IEnumerable<Plane> planes)
        {
            Planes = planes.ToList();
        }

        public List<PassengerPlane> GetPassengersPlanes()
        {

            return Planes.OfType<PassengerPlane>().ToList();
        }

        public List<MilitaryPlane> GetMilitaryPlanes()
        {

            return Planes.OfType<MilitaryPlane>().ToList();
        }

        public PassengerPlane GetPassengerPlaneWithMaxPassengersCapacity()
        {

            return Planes.OfType<PassengerPlane>()
                   .OrderByDescending(plane => plane.PassengersCapacityIs())
                   .FirstOrDefault();
        }

        public List<MilitaryPlane> GetTransportMilitaryPlanes()
        {

            return GetMilitaryPlanes()
                         .Where(plane => plane.PlaneTypeIs() == MilitaryType.TRANSPORT)
                         .ToList();
        }


        public Airport SortBy(Func<Plane, double> keySelector)
        {
            return new Airport(Planes.OrderBy(keySelector));
        }


        public IEnumerable<Plane> GetPlanes()
        {
            return Planes;
        }

        public override string ToString()
        {

            var planeModels = Planes.Select(x => x.GetModel());
            return $"Airport{{ planes = {string.Join(", ", planeModels)} }}";
        }
    }
}
