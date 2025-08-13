# A simple compressor with optional smoothing for DSP in C++
Very basic compressor implimentation with optional smoothing. The smoothing is rather aggressive and needs careful tuning to case by case basis.

## Example usage

Build the project, then execute the command 
```
cmake --build build --target run_example
```
to see the results of the signal compression.


## Realistic usage
Often, the details like sample rate aren't available at the time the compressor *should* be initialized, so declaring it as 
``` 
std::optional<Compressor> compressor;
```
then, when the required details are exposed to the processor, initilizing it in place using 
```
compressor.emplace(/* constructor args */);
```
is the most practical implimentation I have found within my workflow.