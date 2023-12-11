#include <saber/saber.hpp>
#include <saber/util.hpp>

using namespace saber;

struct Hype : Command {
	explicit Hype(Saber *creator)
		: Command(
			  creator,
			  CommandOptions{
				  "hype",
				  DIRNAME,
				  true,
				  {},
				  {},
				  {},
				  {},
				  {"hypu", "train"},
				  "hype",
				  "",
				  {ekizu::Permissions::SendMessages,
				   ekizu::Permissions::EmbedLinks},
				  {},
				  {},
				  {},
				  0,
			  }) {}

	void setup() override {}

	void execute(const ekizu::Message &message,
				 const std::vector<std::string> &args) override {
		if (!args.empty()) { return; }

		const std::string &selectedHype =
			hypu[util::get_random_number<size_t>(0, hypu.size() - 1)];
		std::string msg = ":train2: CHOO CHOO " + selectedHype;

		(void)bot->http.create_message(message.channel_id).content(msg).send();
	}

   private:
	std::vector<std::string> hypu{
		"https://cdn.discordapp.com/attachments/102817255661772800/"
		"219514281136357376/tumblr_nr6ndeEpus1u21ng6o1_540.gif",
		"https://cdn.discordapp.com/attachments/102817255661772800/"
		"219518372839161859/tumblr_n1h2afSbCu1ttmhgqo1_500.gif",
		"https://gfycat.com/HairyFloweryBarebirdbat",
		"https://i.imgur.com/PFAQSLA.gif",
		"https://abload.de/img/ezgif-32008219442iq0i.gif",
		"https://i.imgur.com/vOVwq5o.jpg",
		"https://i.imgur.com/Ki12X4j.jpg",
		"https://media.giphy.com/media/b1o4elYH8Tqjm/giphy.gif"};
};

COMMAND_ALLOC(Hype)
COMMAND_FREE(Hype)
