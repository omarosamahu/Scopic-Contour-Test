#include <gtest/gtest.h>
#include <Contour.h>
#include <future>
#include <mutex>

using namespace Geometery;

std::mutex _mtx;
std::vector<std::shared_ptr<Countour>> getValid(const std::vector<std::shared_ptr<Countour>> &contours)
{
    std::lock_guard<std::mutex> lcm(_mtx);
    std::vector<std::shared_ptr<Countour>> valid;
    for (size_t i = 0; i < contours.size(); i++)
    {
        if (contours[i]->isValid())
        {
            valid.emplace_back(contours[i]);
        }
    }
    return valid;
}

std::vector<std::shared_ptr<Countour>> getInValid(const std::vector<std::shared_ptr<Countour>> &contours)
{
    std::lock_guard<std::mutex> lcm(_mtx);
    std::vector<std::shared_ptr<Countour>> invalid;
    for (size_t i = 0; i < contours.size(); i++)
    {
        if (!contours[i]->isValid())
        {
            invalid.emplace_back(contours[i]);
        }
    }
    return invalid;
}
TEST(ContourTest, HandlesInvalidContours)
{
    Shape line1 = Line({1.0, 4.0}, {5.0, 0.0});
    Shape arc1 = Arc({5.0, 2.0}, 2.0, -90.0, 0.0);

    auto linePtr1 = std::make_shared<Shape>(line1);
    auto arcPtr1 = std::make_shared<Shape>(arc1);

    auto cPtr1 = std::make_shared<Countour>(1e-6);

    cPtr1->addSegment(linePtr1);
    cPtr1->addSegment(arcPtr1);

    Shape line2 = Line({3.0, 4.0}, {1.0, 6.0});
    Shape arc2 = Arc({5.0, 2.0}, 2.0, -45.0, 0.0);

    auto linePtr2 = std::make_shared<Shape>(line2);
    auto arcPtr2 = std::make_shared<Shape>(arc2);

    auto cPtr2 = std::make_shared<Countour>(1e-6);

    cPtr2->addSegment(linePtr2);
    cPtr2->addSegment(arcPtr2);

    std::vector<std::shared_ptr<Countour>> contours;

    contours.emplace_back(std::move(cPtr1));
    contours.emplace_back(std::move(cPtr2));

    auto future = std::async(std::launch::async, getValid, contours);
    auto invalidFuture = std::async(std::launch::async, getInValid, contours);

    auto result = future.get();
    auto invalid = invalidFuture.get();

    EXPECT_TRUE(result[0]->isValid());
    EXPECT_FALSE(invalid[0]->isValid());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
