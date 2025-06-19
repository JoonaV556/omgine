#include <string>
class AudioSource
{
public:
    // > AudioSource Component > Bool playOnStart > Bool loop > Audiofile(waw)

    bool playOnStart = false;
    bool enableLooping = false;
    std::string audioFilePath = "";

    void Play();
};