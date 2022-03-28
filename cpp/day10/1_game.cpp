#include <iostream>
#include <string>
#include <fstream>
using namespace std;

char to_upper(char);
int l(string);
string toUpWord(string);
int main()
{
    int z = rand() % 3 + 1;
    string user = "";
    char temp = ' ';
    string str = " ";
    int choose;
    string bararan[] = { "Aberdeen", "Abilene", "Akron", "Albany", "Albuquerque", "Alexandria", "Allentown", "Amarillo", "Anaheim", "Anchorage", "Ann Arbor", "Antioch", "Apple Valley", "Appleton", "Arlington", "Arvada", "Asheville", "Athens", "Atlanta", "Atlantic City", "Augusta", "Aurora", "Austin", "Bakersfield", "Baltimore", "Barnstable", "Baton Rouge", "Beaumont", "Bel Air", "Bellevue", "Berkeley", "Bethlehem", "Billings", "Birmingham", "Bloomington", "Boise", "Boise City", "Bonita Springs", "Boston", "Boulder", "Bradenton", "Bremerton", "Bridgeport", "Brighton", "Brownsville", "Bryan", "Buffalo", "Burbank", "Burlington", "Cambridge", "Canton", "Cape Coral", "Carrollton", "Cary", "Cathedral City", "Cedar Rapids", "Champaign", "Chandler", "Charleston", "Charlotte", "Chattanooga", "Chesapeake", "Chicago", "Chula Vista", "Cincinnati", "Clarke County", "Clarksville", "Clearwater", "Cleveland", "College Station", "Colorado Springs", "Columbia", "Columbus", "Concord", "Coral Springs", "Corona", "Corpus Christi", "Costa Mesa", "Dallas", "Daly City", "Danbury", "Davenport", "Davidson County", "Dayton", "Daytona Beach", "Deltona", "Denton", "Denver", "Des Moines", "Detroit", "Downey", "Duluth", "Durham", "El Monte", "El Paso", "Elizabeth", "Elk Grove", "Elkhart", "Erie", "Escondido", "Eugene", "Evansville", "Fairfield", "Fargo", "Fayetteville", "Fitchburg", "Flint", "Fontana", "Fort Collins", "Fort Lauderdale", "Fort Smith", "Fort Walton Beach", "Fort Wayne", "Fort Worth", "Frederick", "Fremont", "Fresno", "Fullerton", "Gainesville", "Garden Grove", "Garland", "Gastonia", "Gilbert", "Glendale", "Grand Prairie", "Grand Rapids", "Grayslake", "Green Bay", "GreenBay", "Greensboro", "Greenville", "Gulfport-Biloxi", "Hagerstown", "Hampton", "Harlingen", "Harrisburg", "Hartford", "Havre de Grace", "Hayward", "Hemet", "Henderson", "Hesperia", "Hialeah", "Hickory", "High Point", "Hollywood", "Honolulu", "Houma", "Houston", "Howell", "Huntington", "Huntington Beach", "Huntsville", "Independence", "Indianapolis", "Inglewood", "Irvine", "Irving", "Jackson", "Jacksonville", "Jefferson", "Jersey City", "Johnson City", "Joliet", "Kailua", "Kalamazoo", "Kaneohe", "Kansas City", "Kennewick", "Kenosha", "Killeen", "Kissimmee", "Knoxville", "Lacey", "Lafayette", "Lake Charles", "Lakeland", "Lakewood", "Lancaster", "Lansing", "Laredo", "Las Cruces", "Las Vegas", "Layton", "Leominster", "Lewisville", "Lexington", "Lincoln", "Little Rock", "Long Beach", "Lorain", "Los Angeles", "Louisville", "Lowell", "Lubbock", "Macon", "Madison", "Manchester", "Marina", "Marysville", "McAllen", "McHenry", "Medford", "Melbourne", "Memphis", "Merced", "Mesa", "Mesquite", "Miami", "Milwaukee", "Minneapolis", "Miramar", "Mission Viejo", "Mobile", "Modesto", "Monroe", "Monterey", "Montgomery", "Moreno Valley", "Murfreesboro", "Murrieta", "Muskegon", "Myrtle Beach", "Naperville", "Naples", "Nashua", "Nashville", "New Bedford", "New Haven", "New London", "New Orleans", "New York", "New York City", "Newark", "Newburgh", "Newport News", "Norfolk", "Normal", "Norman", "North Charleston", "North Las Vegas", "North Port", "Norwalk", "Norwich", "Oakland", "Ocala", "Oceanside", "Odessa", "Ogden", "Oklahoma City", "Olathe", "Olympia", "Omaha", "Ontario", "Orange", "Orem", "Orlando", "Overland Park", "Oxnard", "Palm Bay", "Palm Springs", "Palmdale", "Panama City", "Pasadena", "Paterson", "Pembroke Pines", "Pensacola", "Peoria", "Philadelphia", "Phoenix", "Pittsburgh", "Plano", "Pomona", "Pompano Beach", "Port Arthur", "Port Orange", "Port Saint Lucie", "Port St. Lucie", "Portland", "Portsmouth", "Poughkeepsie", "Providence", "Provo", "Pueblo", "Punta Gorda", "Racine", "Raleigh", "Rancho Cucamonga", "Reading", "Redding", "Reno", "Richland", "Richmond", "Richmond County", "Riverside", "Roanoke", "Rochester", "Rockford", "Roseville", "Round Lake Beach", "Sacramento", "Saginaw", "Saint Louis", "Saint Paul", "Saint Petersburg", "Salem", "Salinas", "Salt Lake City", "San Antonio", "San Bernardino", "San Buenaventura", "San Diego", "San Francisco", "San Jose", "Santa Ana", "Santa Barbara", "Santa Clara", "Santa Clarita", "Santa Cruz", "Santa Maria", "Santa Rosa", "Sarasota", "Savannah", "Scottsdale", "Scranton", "Seaside", "Seattle", "Sebastian", "Shreveport", "Simi Valley", "Sioux City", "Sioux Falls", "South Bend", "South Lyon", "Spartanburg", "Spokane", "Springdale", "Springfield", "St. Louis", "St. Paul", "St. Petersburg", "Stamford", "Sterling Heights", "Stockton", "Sunnyvale", "Syracuse", "Tacoma", "Tallahassee", "Tampa", "Temecula", "Tempe", "Thornton", "Thousand Oaks", "Toledo", "Topeka", "Torrance", "Trenton", "Tucson", "Tulsa", "Tuscaloosa", "Tyler", "Utica", "Vallejo", "Vancouver", "Vero Beach", "Victorville", "Virginia Beach", "Visalia", "Waco", "Warren", "Washington", "Waterbury", "Waterloo", "West Covina", "West Valley City", "Westminster", "Wichita", "Wilmington", "Winston", "Winter Haven", "Worcester", "Yakima", "Yonkers", "York", "Youngstown" };
    int l1 = 2 * (sizeof(bararan) / sizeof(bararan[0]));
    string addarr[l1];
    cout << l1;
    cout << "Computer player is 1. User player is  2. " << endl;
    cin >> choose;
    bool b = false;

    str = bararan[z];
    int j = 0;
    if (choose == 1) {

        cout << "--->>" << bararan[z] << endl;
        while (true) {
            addarr[j] = str;
            j++;
        region1:
            cout << "Start user: ";
            cin >> user;
            for (int k = 0; k <= l1; k++) {
                if (toUpWord(user) == toUpWord(addarr[k])) {
                    cout << "This wore alredy use:" << endl;
                    goto region1;
                }
            }

            temp = user[0];
            if (to_upper(temp) == to_upper(str[l(str) - 1])) {
                addarr[j] = user;
                for (int i = 0; i < sizeof(bararan) / sizeof(bararan[0]); i++) {

                    if (to_upper(user[l(user) - 1]) == to_upper(bararan[i][0])) {

                        for (int k = 0; k <= l1; k++) {
                            if (toUpWord(bararan[i]) == toUpWord(addarr[k])) {
                                b = true;
                                break;
                            }
                        }
                        if (b == true) {
                            b = false;

                            continue;
                        }
                        else {
                            cout << "--->>" << bararan[i] << endl;
                            str = bararan[i];
                            b = false;

                            j++;
                            break;
                        }
                    }

                    /*if (i == 5 && r==1 && r!=2) {
                        cout << "Finish you are winner";
                    }*/
                }
            }
            else {

                cout << "Word must start in " << str[l(str) - 1] << endl;
                goto region1;
                return 0;
            }
        }
    }
    else if (choose == 2) {
        cout << "Start user:  ";
        cin >> user;

        while (true) {
        //cin.ignore();

        //getline(cin, user);

        /*for (int k = 0; k <= l1; k++) {
                if (toUpWord(user) == toUpWord(addarr[k])) {
                    cout << "This wore alredy use:";
                    goto region2;
                }
            }*/
        region2:
            addarr[j] = user;
            temp = user[l(user) - 1];

            for (int i = 0; i < sizeof(bararan) / sizeof(bararan[0]); i++) {

                if (to_upper(temp) == to_upper(bararan[i][0])) {

                    ///////
                    for (int k = 0; k <= l1; k++) {
                        if (toUpWord(bararan[i]) == toUpWord(addarr[k])) {
                            b = true;
                            break;
                        }
                    }
                    if (b == true) {
                        b = false;

                        continue;
                    }
                    else {
                        cout << "--->>" << bararan[i] << endl;
                        str = bararan[i];
                        b = false;

                        j++;
                        addarr[j] = str;
                        j++;
                        break;
                    }
                }
            }
        region3:
            cout << "Start User: ";
            cin >> user;
            for (int k = 0; k <= l1; k++) {
                if (toUpWord(user) == toUpWord(addarr[k])) {
                    cout << "This wore alredy use:" << endl;
                    goto region3;
                }
            }

            if (to_upper(str[l(str) - 1]) == to_upper(user[0])) {
                goto region2;
            }
            else {
                cout << "Word must start in " << str[l(str) - 1] << endl;
                goto region3;
            }
        }
    }

    return 0;
}

int l(string a)
{
    int k = 0;
    for (int i = 0; a[i] != '\0'; i++) {
        k++;
    }
    return k;
}

char to_upper(char a)
{
    if (a >= 'a' && a <= 'z') {
        return a - 32;
    }
    return a;
}

string toUpWord(string a)
{
    string b = "";
    for (int i = 0; a[i] != '\0'; i++) {
        b += to_upper(a[i]);
    }
    return b;
}

