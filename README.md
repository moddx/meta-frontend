#meta-frontend

This repository represents frontend-library of the project.
It is used to integrate the plattform into client applications.

It uses CMake.

## Dependencies
This library depends on [backcurl](https://github.com/Taymindis/backcurl), 
and the [meta-core](https://github.com/moddx/meta-core) library.

## How to use
1. Clone `git clone https://github.com/moddx/meta-frontend`
2. Fetch submodules

        git submodules update --init --recursive

3. Add to your CMakeLists.txt

        add_subdirectory(my/libs/meta-frontend/)
        target_link_libraries(mytarget <my-dependencies..> meta-frontend)

4. Implement a custom ComputeUnit und ComputeData class
5. Distribute vectors of ComputeData's over the Distribtor

        # Example
    
        DataSource data(listOfMyComputeData);

        ComputeUnit *cu = new MyComputeUnit();
        Distributor d = new Distributor(cu, '192.168.2.100:4300', 'a4f202ec79d9be281e5e44e15ec75fa8');
        d.distribute(&data);    // blocks

        vector<MyComputeData*> results;
        data.getTypedResults<MyComputeData>(results);
        ..

