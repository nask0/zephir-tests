namespace Basics;

class Base
{
    public function test()
    {
        int i = 0;
        int arrayLength = 0;

        var testArray = ["Hello Universe !", true, false, 86, 12.22, null];
        let arrayLength = count(testArray);

        /* Print value types */
        while i < arrayLength {
            echo "typeof testArray[", i, "] : ", typeof testArray[i];
            echo "<br />";
            var_dump(testArray[i]);
            echo "<br />";
            echo "<br />";

            let i++;
        }

        return testArray;
    }
}