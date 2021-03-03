#include "dy_array.h"

namespace charptr0
{
    template <typename data_type>
    dy_Array<data_type>::dy_Array() {this->size = 0;} //if no arguments are given, set up an empty array 

    template <typename data_type>
    dy_Array<data_type>::dy_Array(const data_type &inital_data) //set the inital_data to be the first element of the array
    {
        this->data_ptr = new data_type[1];
        data_ptr[0] = inital_data;
        this->size = 1; //set the size to 1
    }

    template <typename data_type>
    void dy_Array<data_type>::append(const data_type &data) //append an element 
    {
        if(size == 0) //if the array is empty, set the data to be the first element
        {
            this->data_ptr = new data_type[1];
            this->data_ptr[0] = data;
            this->size = 1;
            return;
        }

        this->size++; //increment size by 1

        data_type* modified_data = new data_type[size]; //create a new temp array with the new size

        for(size_t i = 0; i < size-1; i++) {modified_data[i] = data_ptr[i];} //copy the values over to the temp array

        modified_data[size-1] = data; //append the data to the end of the temp array

        free(data_ptr); 

        data_ptr = new data_type[size]; //allocate the main array with the correct size

        for(size_t i = 0; i < size; i++) {data_ptr[i] = modified_data[i];} //copy back the values including the new element

        delete modified_data; //free the memory and delete the temp array
    }

    template <typename data_type>
    data_type* dy_Array<data_type>::array() const
    {
        return this->data_ptr;
    }

    template <typename data_type>
    size_t dy_Array<data_type>::length() const {return this->size;}

}