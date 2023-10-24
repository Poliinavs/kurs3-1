using Aircompany.Models;
using Aircompany.Planes;
using System;
using System.Collections.Generic;

namespace Aircompany
{
    public class Runner
    {
       
        public static void Main(string[] args)
        {
            Airport airport = new Airport(RegPlain.Planes);

            Airport militaryAirport = new Airport(airport.GetMilitaryPlanes());
            Airport passengerAirport = new Airport(airport.GetPassengersPlanes());
            Console.WriteLine(militaryAirport
                              .SortBy(plane => plane.MaxFlightDistance())
                             .ToString());

            Console.WriteLine(passengerAirport
                .SortBy(plane => plane.GetMS())
                .ToString());

            Console.WriteLine(passengerAirport.GetPassengerPlaneWithMaxPassengersCapacity());           
        }
    }
}
